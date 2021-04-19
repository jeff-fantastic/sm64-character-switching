//#include"bruh_maplang.h"
// turn hmsXXX into geolayout

#include "mgeo2.inc.c"
/*
#else

#define	_msU32(dat) ((unsigned long)(dat*65536.0f))
#define RM_SURF LAYER_OPAQUE
#define hmsBegin() GEO_OPEN_NODE(),
#define hmsEnd() GEO_CLOSE_NODE(),
#define hmsSelect(code, proc) GEO_SWITCH_CASE(code, proc),
#define hmsGfx(x,y) GEO_DISPLAY_LIST(x,y),
#define hmsReturn() GEO_RETURN(),
#define hmsJoint(mode,gfx,px,py,pz) GEO_ANIMATED_PART(mode,px,py,pz,gfx),
//GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
#define hmsShadow(size,level,flag) GEO_SHADOW(flag,level,size),
#define hmsScale(f) GEO_SCALE(0, _msU32(f)), // TODO
//#define hmsCall(r) GEO_ASM(0, r),
#define hmsCall(r) GEO_BRANCH(1, r),
#define hmsExit() GEO_END(),
#define hmsLOD(near,far) GEO_RENDER_RANGE(near,far),
#define hmsCProg(code, proc) GEO_ASM(code, proc),
#define hmsRotate(ax,ay,az) GEO_ROTATION_NODE(0, ax,ay,az),
#define hmsGroup() GEO_NODE_START(),
#define hmsSucker(x, y, z, w, dl) GEO_HELD_OBJECT(x, y, z, w, dl),
#define Hierarchy const GeoLayout*/

/********************************************************************************/
/*	Title luigi hierarchy data.													*/
/********************************************************************************/

static Hierarchy RCP_TitleLuigiHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 261-189, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_luigi_near14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_luigi_near_body, 33, 0, 0)					/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 91, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsSelect(0, geo_switch_mario_eyes /* TODO: CtrlMarioEye */) // the first number was 1 for player 2
						hmsBegin()
							hmsGfx(RM_SURF, RCP_luigi_head1)
							hmsGfx(RM_SURF, RCP_luigi_head2)
							hmsGfx(RM_SURF, RCP_luigi_head3)
							hmsGfx(RM_SURF, RCP_luigi_head4)
							hmsGfx(RM_SURF, RCP_luigi_head5)
							hmsGfx(RM_SURF, RCP_luigi_head5)
							hmsGfx(RM_SURF, RCP_luigi_head5)
							hmsGfx(RM_SURF, RCP_luigi_head6)
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 63, -10, 65)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near1, 63, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)		/* m_lhamd1_2	*/
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 60, -10, -63)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near4, 62, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
								hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)		/* m_rhand1_2	*/
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, 39)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_near11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near10, 98, 0, 0)			/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near9, 81, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, -40)							/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_near8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near7, 98, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near6, 81, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Near luigi hierarchy data.													*/
/********************************************************************************/

static Hierarchy RCP_NearLuigiHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 261-189, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_luigi_near14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_luigi_near_body, 33, 0, 0)					/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 91, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
						hmsRotate(0, 0, 0)								/* for control by program	*/
						hmsBegin()
							hmsSelect(1, geo_switch_mario_eyes /* TODO: CtrlMarioEye */)					/* for the eye animation	*/
							hmsBegin()
								hmsGfx(RM_SURF, RCP_luigi_head1)
								hmsGfx(RM_SURF, RCP_luigi_head2)
								hmsGfx(RM_SURF, RCP_luigi_head3)
								hmsGfx(RM_SURF, RCP_luigi_head4)
								hmsGfx(RM_SURF, RCP_luigi_head5)
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 63, -10, 65)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near1, 63, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_near0, 71, 0, 0)		/* m_lhamd1_2	*/
									hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 60, -10, -63)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near4, 62, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
								hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_near3, 66, 0, 0)		/* m_rhand1_2	*/
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 2
									hmsJoint(RM_SURF, RCP_mario_vsign_hand, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, 39)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_near11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near10, 98, 0, 0)			/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near9, 81, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, -40)							/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_near8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_near7, 98, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_near6, 81, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Middle luigi hierarchy data.												*/
/********************************************************************************/

static Hierarchy RCP_MidLuigiHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 261-189, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_luigi_mid14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_luigi_mid_body, 33, 0, 0)						/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 91, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
						hmsRotate(0, 0, 0)								/* for control by program	*/
						hmsBegin()
							hmsSelect(1, geo_switch_mario_eyes /* TODO: CtrlMarioEye */)					/* for the eye animation	*/
							hmsBegin()
								hmsGfx(RM_SURF, RCP_luigi_head1)
								hmsGfx(RM_SURF, RCP_luigi_head2)
								hmsGfx(RM_SURF, RCP_luigi_head3)
								hmsGfx(RM_SURF, RCP_luigi_head4)
								hmsGfx(RM_SURF, RCP_luigi_head5)
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 63, -10, 65)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_mid2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_mid1, 63, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_mid0 , 71, 0, 0)		/* m_lhamd1_2	*/
									hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 60, -10, -63)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_mid5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_mid4, 62, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
								hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_mid3 , 66, 0, 0)		/* m_rhand1_2	*/
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 2
									hmsJoint(RM_SURF, RCP_mario_vsign_hand, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, 39)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_mid11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_mid10, 98, 0, 0)				/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_mid9, 81, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, -40)							/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_mid8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_mid7, 98, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_mid6, 81, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Far luigi hierarchy data.													*/
/********************************************************************************/

static Hierarchy RCP_FarLuigiHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 261-189, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_luigi_far14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_luigi_far13, 33, 0, 0)						/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 91, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
						hmsRotate(0, 0, 0)								/* for control by program	*/
						hmsBegin()
							hmsGfx(RM_SURF, RCP_luigi_far12)
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 63, -10, 65)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_far2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_far1, 63, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_far0 , 71, 0, 0)		/* m_lhamd1_2	*/
									hmsJoint(RM_SURF, RCP_swim_hand_l, 71, 0, 0)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 60, -10, -63)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_far5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_far4, 62, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
								hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_luigi_far3 , 66, 0, 0)		/* m_rhand1_2	*/
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									hmsJoint(RM_SURF, RCP_swim_hand_r, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 2
									hmsJoint(RM_SURF, RCP_mario_vsign_hand, 66, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, 39)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_far11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_far10, 98, 0, 0)				/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_far9, 81, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, -34, -9, -40)							/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_luigi_far8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_luigi_far7, 98, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_luigi_far6, 81, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsReturn()
};

/********************************************************************************/
/*	Luigi hierarchy map data.													*/
/********************************************************************************/

Hierarchy RCP_LuigiHierarchy[] = {
	//GEO_NODE_START(),
 	hmsShadow(100, 180, 99)
	hmsBegin()
		hmsScale(0.25f)
		hmsBegin()
			hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioLOD */)
			hmsBegin()
				//hmsCall(RCP_NearLuigiHierarchy)
				hmsGroup()
				hmsBegin()
					hmsLOD(-2048,600)
					hmsBegin()
						hmsCall(RCP_NearLuigiHierarchy)
					hmsEnd()

					hmsLOD(600,1600)
					hmsBegin()
						hmsCall(RCP_MidLuigiHierarchy)
					hmsEnd()

					hmsLOD(1600,32767)
					hmsBegin()
						hmsCall(RCP_FarLuigiHierarchy)
					hmsEnd()
				hmsEnd()
			hmsEnd()
		hmsEnd()
	hmsEnd()
	hmsExit()
};
/********************************************************************************/
/*	Lugi hierarchy map data for title.											*/
/********************************************************************************/

Hierarchy RCP_TitleLuigi[] = {
 	hmsShadow(100, 180, 99)
	hmsBegin()
		hmsScale(0.25f)
		hmsBegin()
			hmsCall(RCP_TitleLuigiHierarchy)
		hmsEnd()
	hmsEnd()
	hmsReturn() // was hmsExit()
};
/*
#define hmsCall2(a, r) GEO_BRANCH(a, r),
Hierarchy RCP_TitlePlayer[] = {
	GEO_NODE_START(),
	hmsBegin()
		hmsSelect(2, geo_switch_mario_player /* TODO: CtrlMarioLOD * /)
		hmsBegin()
			hmsCall(RCP_MarioHierarchy)
			hmsCall(RCP_LuigiHierarchy)
		hmsEnd()
	hmsEnd()
	hmsExit()
};*/
//#endif//LUIGI