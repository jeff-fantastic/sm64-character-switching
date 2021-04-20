/********************************************************************************
                        Ultra 64 MARIO Brothers

                      luigi hierarcky data module

            Copyright 1995 Nintendo co., ltd.  All rights reserved

                This module was programmed by Y.Nishida

                            June 20, 1995
 ********************************************************************************/

//#include "../headers.h"

/********************************************************************************/
/*    Title luigi hierarchy data.                                                    */
/********************************************************************************/

#define RM_SURF LAYER_OPAQUE
#define hmsScale(f) GEO_SCALE(0, _msU32(f)),
#define hmsBegin() GEO_OPEN_NODE(),
#define hmsEnd() GEO_CLOSE_NODE(),
#define hmsCall(r) GEO_BRANCH(1, r),
#define hmsReturn() GEO_RETURN(),
#define hmsCProg(x, prog) GEO_ASM(x, prog),
#define hmsRotate(x, y, z) GEO_ROTATION_NODE(0x00, x, y, z),
#define hmsJoint(type, ptr, x, y, z) GEO_ANIMATED_PART(type, x, y, z, ptr),
#define hmsGfx(type, dl) GEO_DISPLAY_LIST(type, dl),
#define hmsSucker(x, y, z, w, dl) GEO_HELD_OBJECT(x, y, z, w, dl),
#define hmsSelect(x, arg) GEO_SWITCH_CASE(x, arg),

static const GeoLayout RCP_TitleLuigiHierarchy[] = {
        hmsJoint(RM_SURF, NULL, 0, 261-189, 0)
        GEO_OPEN_NODE(),
            hmsJoint(RM_SURF, RCP_luigi_near14, 0, 0, 0)
            GEO_OPEN_NODE(),
                hmsJoint(RM_SURF, RCP_luigi_near_body, 33, 0, 0)
                GEO_OPEN_NODE(),

                    hmsJoint(RM_SURF, NULL, 91, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsSelect(1, geo_switch_mario_eyes)
                        GEO_OPEN_NODE(),
                            hmsGfx(RM_SURF, RCP_luigi_head1)
                            hmsGfx(RM_SURF, RCP_luigi_head2)
                            hmsGfx(RM_SURF, RCP_luigi_head3)
                            hmsGfx(RM_SURF, RCP_luigi_head4)
                            hmsGfx(RM_SURF, RCP_luigi_head5)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 63, -10, 65)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_near2, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_near1, 63, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 60, -10, -63)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_near5, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_near4, 62, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, 39)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_near11, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_near10, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_near9, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, -40)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_near8, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_near7, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_near6, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_RETURN(),
};

/********************************************************************************/
/*    Near luigi hierarchy data.                                                    */
/********************************************************************************/

static const GeoLayout RCP_NearLuigiHierarchy[] = {
    hmsJoint(RM_SURF, NULL, 0, 261-189, 0)
        hmsBegin()
            hmsJoint(RM_SURF, RCP_luigi_near14, 0, 0, 0)
            hmsBegin()
                hmsJoint(RM_SURF, RCP_luigi_near_body, 33, 0, 0)
                hmsBegin()

                    hmsJoint(RM_SURF, NULL, 91, 0, 0)
                    hmsBegin()
                        hmsCProg(1, geo_mario_head_rotation)
                        hmsRotate(0, 0, 0)
                        hmsBegin()
                            hmsSelect(1, geo_switch_mario_eyes)
                            hmsBegin()
                                hmsGfx(RM_SURF, RCP_luigi_head1)
                                hmsGfx(RM_SURF, RCP_luigi_head2)
                                hmsGfx(RM_SURF, RCP_luigi_head3)
                                hmsGfx(RM_SURF, RCP_luigi_head4)
                                hmsGfx(RM_SURF, RCP_luigi_head5)
                                hmsGfx(RM_SURF, RCP_luigi_head6)
                                hmsGfx(RM_SURF, RCP_luigi_head7)
                                hmsGfx(RM_SURF, RCP_luigi_head8)
                            hmsEnd()
                        hmsEnd()
                    hmsEnd()

                    hmsJoint(RM_SURF, NULL, 63, -10, 65)
                    hmsBegin()
                        hmsJoint(RM_SURF, RCP_luigi_near2, 0, 0, 0)
                        hmsBegin()
                            hmsJoint(RM_SURF, RCP_luigi_near1, 63, 0, 0)
                            hmsBegin()
                                hmsSelect(1, geo_switch_mario_hand)
                                hmsBegin()
                                    hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)
                                hmsEnd()
                            hmsEnd()
                        hmsEnd()
                    hmsEnd()

                    hmsJoint(RM_SURF, NULL, 60, -10, -63)
                    hmsBegin()
                        hmsJoint(RM_SURF, RCP_luigi_near5, 0, 0, 0)
                        hmsBegin()
                            hmsJoint(RM_SURF, RCP_luigi_near4, 62, 0, 0)
                            hmsBegin()
                                hmsSelect(1, geo_switch_mario_hand)
                                hmsBegin()
                                    hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)
                                    hmsBegin()
                                        hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos)
                                    hmsEnd()
                                    hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
                                    hmsBegin()
                                        hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos)
                                    hmsEnd()
                                    hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)
                                    hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)
                                    hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)
                                hmsEnd()
                            hmsEnd()
                        hmsEnd()
                    hmsEnd()

                hmsEnd()

                hmsJoint(RM_SURF, NULL, -34, -9, 39)
                hmsBegin()
                    hmsJoint(RM_SURF, RCP_luigi_near11, 0, 0, 0)
                    hmsBegin()
                        hmsJoint(RM_SURF, RCP_luigi_near10, 98, 0, 0)
                        hmsBegin()
                            hmsJoint(RM_SURF, RCP_luigi_near9, 81, 0, 0)
                        hmsEnd()
                    hmsEnd()
                hmsEnd()

                hmsJoint(RM_SURF, NULL, -34, -9, -40)
                hmsBegin()
                    hmsJoint(RM_SURF, RCP_luigi_near8, 0, 0, 0)
                    hmsBegin()
                        hmsJoint(RM_SURF, RCP_luigi_near7, 98, 0, 0)
                        hmsBegin()
                            hmsJoint(RM_SURF, RCP_luigi_near6, 81, 0, 0)
                        hmsEnd()
                    hmsEnd()
                hmsEnd()

            hmsEnd()
        hmsEnd()
    hmsReturn()
};

/********************************************************************************/
/*    Middle luigi hierarchy data.                                                */
/********************************************************************************/
/*
static const GeoLayout RCP_MidLuigiHierarchy[] = {
        hmsJoint(RM_SURF, NULL, 0, 261-189, 0)
        GEO_OPEN_NODE(),
            hmsJoint(RM_SURF, RCP_luigi_mid14, 0, 0, 0)
            GEO_OPEN_NODE(),
                hmsJoint(RM_SURF, RCP_luigi_mid_body, 33, 0, 0)
                GEO_OPEN_NODE(),

                    hmsJoint(RM_SURF, NULL, 91, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsCProg(1, CtrlMarioHead)
                        hmsRotate(0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsSelect(1, CtrlMarioEye)
                            GEO_OPEN_NODE(),
                                hmsGfx(RM_SURF, RCP_luigi_head1)
                                hmsGfx(RM_SURF, RCP_luigi_head2)
                                hmsGfx(RM_SURF, RCP_luigi_head3)
                                hmsGfx(RM_SURF, RCP_luigi_head4)
                                hmsGfx(RM_SURF, RCP_luigi_head5)
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 63, -10, 65)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_mid2, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_mid1, 63, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsSelect(1, CtrlMarioHand)
                                GEO_OPEN_NODE(),
                                    hmsJoint(RM_SURF, RCP_luigi_mid0 , 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
                                GEO_CLOSE_NODE(),
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 60, -10, -63)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_mid5, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_mid4, 62, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsSelect(1, CtrlMarioHand)
                                GEO_OPEN_NODE(),
                                    hmsJoint(RM_SURF, RCP_luigi_mid3 , 66, 0, 0)
                                    GEO_OPEN_NODE(),
                                        hmsSucker(0,0,0, 1,CtrlMarioTaking)
                                    GEO_CLOSE_NODE(),
                                    hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
                                    GEO_OPEN_NODE(),
                                        hmsSucker(0,0,0, 1,CtrlMarioTaking)
                                    GEO_CLOSE_NODE(),
                                GEO_CLOSE_NODE(),
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, 39)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_mid11, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_mid10, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_mid9, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, -40)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_mid8, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_mid7, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_mid6, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
    GEO_RETURN(),
};
*/

/********************************************************************************/
/*    Far luigi hierarchy data.                                                    */
/********************************************************************************/
/*
static const GeoLayout RCP_FarLuigiHierarchy[] = {
        hmsJoint(RM_SURF, NULL, 0, 261-189, 0)
        GEO_OPEN_NODE(),
            hmsJoint(RM_SURF, RCP_luigi_far14, 0, 0, 0)
            GEO_OPEN_NODE(),
                hmsJoint(RM_SURF, RCP_luigi_far13, 33, 0, 0)
                GEO_OPEN_NODE(),

                    hmsJoint(RM_SURF, NULL, 91, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsCProg(1, CtrlMarioHead)
                        hmsRotate(0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsGfx(RM_SURF, RCP_luigi_far12)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 63, -10, 65)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_far2, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_far1, 63, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsSelect(1, CtrlMarioHand)
                                GEO_OPEN_NODE(),
                                    hmsJoint(RM_SURF, RCP_luigi_far0 , 71, 0, 0)
                                    hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
                                GEO_CLOSE_NODE(),
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                    hmsJoint(RM_SURF, NULL, 60, -10, -63)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_far5, 0, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_far4, 62, 0, 0)
                            GEO_OPEN_NODE(),
                                hmsSelect(1, CtrlMarioHand)
                                GEO_OPEN_NODE(),
                                    hmsJoint(RM_SURF, RCP_luigi_far3 , 66, 0, 0)
                                    GEO_OPEN_NODE(),
                                        hmsSucker(0,0,0, 1,CtrlMarioTaking)
                                    GEO_CLOSE_NODE(),
                                    hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
                                    GEO_OPEN_NODE(),
                                        hmsSucker(0,0,0, 1,CtrlMarioTaking)
                                    GEO_CLOSE_NODE(),
                                GEO_CLOSE_NODE(),
                            GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),

                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, 39)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_far11, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_far10, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_far9, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

                hmsJoint(RM_SURF, NULL, -34, -9, -40)
                GEO_OPEN_NODE(),
                    hmsJoint(RM_SURF, RCP_luigi_far8, 0, 0, 0)
                    GEO_OPEN_NODE(),
                        hmsJoint(RM_SURF, RCP_luigi_far7, 98, 0, 0)
                        GEO_OPEN_NODE(),
                            hmsJoint(RM_SURF, RCP_luigi_far6, 81, 0, 0)
                        GEO_CLOSE_NODE(),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),

            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
    GEO_RETURN(),
};
*/

/********************************************************************************/
/*    Luigi hierarchy map data.                                                    */
/********************************************************************************/
const GeoLayout luigi_geo[] = {
    GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
    GEO_OPEN_NODE(),
        GEO_SCALE(0x00, 16384),
        GEO_OPEN_NODE(),
            GEO_ASM(0, geo_mirror_mario_backface_culling),
            GEO_ASM(0, geo_mirror_mario_set_alpha),
            GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
            GEO_OPEN_NODE(),
                GEO_BRANCH(1, RCP_NearLuigiHierarchy),
                GEO_NODE_START(),
                GEO_OPEN_NODE(),
                    GEO_RENDER_RANGE(-2048, 600),
                    GEO_OPEN_NODE(),
                        GEO_BRANCH(1, RCP_NearLuigiHierarchy),
                    GEO_CLOSE_NODE(),
                    
                    GEO_RENDER_RANGE(600, 1600),
                    GEO_OPEN_NODE(),
                        GEO_BRANCH(1, RCP_NearLuigiHierarchy),
                        //GEO_BRANCH(1, RCP_MidLuigiHierarchy),
                    GEO_CLOSE_NODE(),
                    
                    GEO_RENDER_RANGE(1600, 32767),
                    GEO_OPEN_NODE(),
                        GEO_BRANCH(1, RCP_NearLuigiHierarchy),
                        //GEO_BRANCH(1, RCP_FarLuigiHierarchy),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_ASM(1, geo_mirror_mario_backface_culling),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
};

/********************************************************************************/
/*    Lugi hierarchy map data for title.                                            */
/********************************************************************************/

const GeoLayout RCP_TitleLuigi[] = {
    GEO_SCALE(0x00, 16384),
    GEO_OPEN_NODE(),
        GEO_BRANCH(1, RCP_TitleLuigiHierarchy),
    GEO_CLOSE_NODE(),
    GEO_END(),
};
