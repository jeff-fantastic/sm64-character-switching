#include <PR/ultratypes.h>

#include "audio/external.h"
#include "engine/math_util.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/level_update.h"
#include "game/main.h"
#include "game/memory.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/sound_init.h"
#include "game/rumble_init.h"
#include "game/object_helpers.h"
#include "game/spawn_object.h"
#include "game/mario.h"
#include "src/menu/file_select.h"
#include "src/game/object_list_processor.h"
#include "level_table.h"
#include "behavior_data.h"
#include "seq_ids.h"
#include "sm64.h"
#include "game/ingame_menu.h"

#define PRESS_START_DEMO_TIMER 800

#define STUB_LEVEL(textname, _1, _2, _3, _4, _5, _6, _7, _8) textname,
#define DEFINE_LEVEL(textname, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) textname,

static char gLevelSelect_StageNamesText[64][16] = {
    #include "levels/level_defines.h"
};
#undef STUB_LEVEL
#undef DEFINE_LEVEL

static u16 gDemoCountdown = 0;
#ifndef VERSION_JP
static s16 D_U_801A7C34 = 1;
static s16 gameOverNotPlayed = 1;
#endif // New variables onwards
float g_selectorYTarget = -370;
float g_selectorYPos = 0;

u8 g_selection;
u8 g_selectionMax;
u16 menuLayer;

u16 g_joystickDelay;
u16 g_joystickDisable;
u8 g_saveNum;

// run the demo timer on the PRESS START screen.
// this function will return a non-0 timer once
// the demo starts, signaling to the subsystem that
// the demo needs to be ran.

// don't shift this function from being the first function in the segment.
// the level scripts assume this function is the first, so it cant be moved.
s32 run_press_start_demo_timer(s32 timer) {
    gCurrDemoInput = NULL;

    if (timer == 0) {
        if (!gPlayer1Controller->buttonDown && !gPlayer1Controller->stickMag) {
            if ((++gDemoCountdown) == PRESS_START_DEMO_TIMER) {
                // start the demo. 800 frames has passed while
                // player is idle on PRESS START screen.

                // start the Mario demo animation for the demo list.
                //load_patchable_table(&gDemo, gDemoInputListID);

                // if the next demo sequence ID is the count limit, reset it back to
                // the first sequence.
                //if (++gDemoInputListID == gDemo.animDmaTable->count) {
                //    gDemoInputListID = 0;
                //}

                // add 1 (+4) to the pointer to skip the demoID.
                //gCurrDemoInput = ((struct DemoInput *) gDemo.targetAnim) + 1;
                //timer = (s8)((struct DemoInput *) gDemo.targetAnim)->timer;
                //gCurrSaveFileNum = 1;
                //gCurrActNum = 1;
            }
        } else { // activity was detected, so reset the demo countdown.
            gDemoCountdown = 0;
        }
    }
    return timer;
}

// input loop for the level select menu. updates the selected stage
// count if an input was received. signals the stage to be started
// or the level select to be exited if start or the quit combo is
// pressed.

s16 level_select_input_loop(void) {
    s32 stageChanged = FALSE;

    // perform the ID updates per each button press.
    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
        ++gCurrLevelNum, stageChanged = TRUE;
    }
    if (gPlayer1Controller->buttonPressed & B_BUTTON) {
        --gCurrLevelNum, stageChanged = TRUE;
    }
    if (gPlayer1Controller->buttonPressed & U_JPAD) {
        --gCurrLevelNum, stageChanged = TRUE;
    }
    if (gPlayer1Controller->buttonPressed & D_JPAD) {
        ++gCurrLevelNum, stageChanged = TRUE;
    }
    if (gPlayer1Controller->buttonPressed & L_JPAD) {
        gCurrLevelNum -= 10, stageChanged = TRUE;
    }
    if (gPlayer1Controller->buttonPressed & R_JPAD) {
        gCurrLevelNum += 10, stageChanged = TRUE;
    }

    // if the stage was changed, play the sound for changing a stage.
    if (stageChanged) {
        play_sound(SOUND_GENERAL_LEVEL_SELECT_CHANGE, gGlobalSoundSource);
    }

    // TODO: enum counts for the stage lists
    if (gCurrLevelNum > LEVEL_MAX) {
        gCurrLevelNum = LEVEL_MIN; // exceeded max. set to min.
    }

    if (gCurrLevelNum < LEVEL_MIN) {
        gCurrLevelNum = LEVEL_MAX; // exceeded min. set to max.
    }

    gCurrSaveFileNum = 4; // file 4 is used for level select tests
    gCurrActNum = 6;
    print_text_centered(160, 80, "SELECT STAGE");
    print_text_centered(160, 30, "PRESS START BUTTON");
    print_text_fmt_int(40, 60, "%2d", gCurrLevelNum);
    print_text(80, 60, gLevelSelect_StageNamesText[gCurrLevelNum - 1]); // print stage name

#define QUIT_LEVEL_SELECT_COMBO (Z_TRIG | START_BUTTON | L_CBUTTONS | R_CBUTTONS)

    // start being pressed signals the stage to be started. that is, unless...
    if (gPlayer1Controller->buttonPressed & START_BUTTON) {
        // ... the level select quit combo is being pressed, which uses START. If this
        // is the case, quit the menu instead.
        if (gPlayer1Controller->buttonDown == QUIT_LEVEL_SELECT_COMBO) {
            gDebugLevelSelect = FALSE;
            return -1;
        }
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
        return gCurrLevelNum;
    }
    return 0;
}

void handle_inputs(u8 type) { // handles menu scrolls, 0 = vertical 1 = horizontal
    handle_menu_scrolling (type == 0 ? MENU_SCROLL_VERTICAL : MENU_SCROLL_HORIZONTAL, &g_selection, 0, g_selectionMax);
}

void print_save_strings(void) { // set of print functions that grab every set of file info
    print_save_file_star_count(0, 180, 90);
    print_save_file_star_count(1, 180, 72);
    print_save_file_star_count(2, 180, 54);
    print_save_file_star_count(3, 180, 36);
}

s32 intro_default(void) { // titlescreen code

    if (D_U_801A7C34 == 1) { // greet player
        if (gGlobalTimer < 0x81) {
            play_sound(SOUND_MARIO_HELLO, gGlobalSoundSource);
        } else {
            play_sound(SOUND_MARIO_PRESS_START_TO_PLAY, gGlobalSoundSource);
        }
        D_U_801A7C34 = 0;
    }

    handle_inputs(0); // handle inputs on y axis

    if (menuLayer != 0) { // if entered titlescreen, handle arrow placements based on selection
        switch (g_selection) {
            case 0:
                g_selectorYTarget = -370;
                break;
            case 1:
                g_selectorYTarget = -495;
                break;
            case 2:
                g_selectorYTarget = -620;
                break;
            case 3:
                g_selectorYTarget = -740;
                break;
            case 4:
                g_selectorYTarget = -860;
        }
    }

    switch (menuLayer) { // based on menuLayer, print appropriate text and set selection cap
        case 0:
            g_selectionMax = 0; // easy fix to disable menu movement before entering title
            if ((gGlobalTimer & 0x1F) < 20) {
                if (gControllerBits == 0) {
                    print_text_centered(SCREEN_WIDTH / 2, 75, "NO CONTROLLER");
                } else {
                    print_text_centered(SCREEN_WIDTH / 2, 75, "PRESS START");
                }
            }
            break;
        case 1:
            g_selectionMax = 4;
            print_text(100, 90, "FILE A");
            print_text(100, 72, "FILE B");
            print_text(100, 54, "FILE C");
            print_text(100, 36, "FILE D");
            print_text(100, 18, "DELETE FILE");
            print_save_strings();
            break;
        case 2:
            g_selectionMax = 4;
            print_text(100, 90, "FILE A");
            print_text(100, 72, "FILE B");
            print_text(100, 54, "FILE C");
            print_text(100, 36, "FILE D");
            print_text(100, 18, "GO BACK");
            print_save_strings();
            break;
    }

    if (gPlayer1Controller->buttonPressed & (START_BUTTON | A_BUTTON)) { // when you press start or the a button...
        switch (menuLayer) {
            case 0: // ...increase menu layer
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                menuLayer++;
                break;
            case 1: // ...load file
                if (g_selection < 4) {
                    g_saveNum = g_selection + 1;
                    g_selection = 0;
                } else {
                    menuLayer = 2;
                    g_selection = 0;
                }
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                break;
            case 2: // ...delete file
                if (g_selection < 4) {
                    save_file_erase(g_selection);
                    play_sound(SOUND_MARIO_DOH, gGlobalSoundSource);
                } else {
                    menuLayer = 1;
                    g_selection = 0;
                    play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                }
        }
    }
    return g_saveNum;
}

s32 intro_character_select(void) { // handles character select
    u8 characterg_selection = 0;

    handle_inputs(1); // get horizontal input

    g_selectionMax = 1; // set max selection (increase this if you're adding extra characters)
    print_text_centered(SCREEN_WIDTH/2, 200, "SELECT A BROTHER");

    switch (g_selection) { // print name of the currently select character
        case 0:
            print_text_centered(SCREEN_WIDTH/2, 48, "SUPER MARIO");
            break;
        case 1:
            print_text_centered(SCREEN_WIDTH/2, 48, "SUPER LUIGI");
            break;
    }
    print_text_centered(SCREEN_WIDTH/2, 30, "PRESS START TO BEGIN");

    if (gPlayer1Controller->buttonPressed & (START_BUTTON | A_BUTTON)) {
        characterg_selection = 1;
        currentCharacter = g_selection; // set ingame character to player's selection
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
    }

    return characterg_selection;
}

s32 intro_game_over(void) {
    s32 sp1C = 0;

#ifndef VERSION_JP
    if (gameOverNotPlayed == 1) {
        play_sound(SOUND_MARIO_GAME_OVER, gGlobalSoundSource);
        gameOverNotPlayed = 0;
    }
#endif

    print_intro_text();

    if (gPlayer1Controller->buttonPressed & START_BUTTON) {
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
#ifdef VERSION_SH
        queue_rumble_data(60, 70);
        func_sh_8024C89C(1);
#endif
        sp1C = 100 + gDebugLevelSelect;
#ifndef VERSION_JP
        gameOverNotPlayed = 1;
#endif
    }
    return run_press_start_demo_timer(sp1C);
}

s32 intro_play_its_a_me_mario(void) {
    set_background_music(0, SEQ_SOUND_PLAYER, 0);
    play_sound(SOUND_MENU_COIN_ITS_A_ME_MARIO, gGlobalSoundSource);
    return 1;
}

s32 lvl_intro_update(s16 arg1, UNUSED s32 arg2) {
    s32 retVar;

    switch (arg1) {
        case 0:
            retVar = intro_play_its_a_me_mario(); // splash screen
            break;
        case 1:
            retVar = intro_default(); // custom titlescreen
            break;
        case 2:
            retVar = intro_game_over(); // (unused) gameover
            break;
        case 3:
            retVar = level_select_input_loop(); // debug menu
            break;
        case 4:
            retVar = intro_character_select(); // custom character select
            break;
    }
    area_update_objects();
    return retVar;
}

// Custom object code relating to the titlescreen onwards

void bhv_selector_loop(void) { // code for the arrow pointer on titlescreen
    if (menuLayer == 0) { // make invisible if you havent entered the menu
        gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    } else {
        gCurrentObject->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    }
    g_selectorYPos = g_selectorYPos + (g_selectorYTarget - g_selectorYPos) * 0.2f; // interpolation formula
    gCurrentObject->oPosY = g_selectorYPos; // go to interpolated position
    gCurrentObject->oPosX = -625.0 + 50.0*sinf(gGlobalTimer/8.0); // neat little bouncy effect LOL
}

void bhv_character_viewer_loop(void) {
    switch (g_selection) { // switches model based on selection
        case 0:
            gCurrentObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_INTRO_CHARACTER_MARIO];
            break;
        case 1:
            gCurrentObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_INTRO_CHARACTER_LUIGI];
            break;
    }
}
