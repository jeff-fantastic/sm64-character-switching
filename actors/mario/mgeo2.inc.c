
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
#define hmsSucker(x, y, z, w, dl) GEO_HELD_OBJECT(0, x, y, z, dl),
#define Hierarchy const GeoLayout

#define CtrlMarioEye geo_switch_mario_eyes
#define CtrlMarioHand geo_switch_mario_hand
#define CtrlMarioHead geo_switch_mario_cap_on_off
#define CtrlMarioTaking geo_switch_mario_hand_grab_pos
#define CtrlMarioLOD geo_switch_mario_hand // ??

extern Gfx RCP_mario_vsign_hand[];
/********************************************************************************/
/*	Title Mario hierarchy data.													*/
/********************************************************************************/

Hierarchy RCP_TitleMarioHierarchy[] = {
	hmsJoint(RM_SURF, NULL, 0, 0, 0)											/* chn14		*/
	hmsBegin()
		hmsJoint(RM_SURF, RCP_mario_near14, 0, 0, 0)							/* m_waist1_3	*/
		hmsBegin()
			//hmsCProg(0, MarioProc1)
			hmsJoint(RM_SURF, RCP_mario_near_body, 68, 0, 0)					/* m_body1		*/
			hmsBegin()

				hmsJoint(RM_SURF, NULL, 87, 0, 0)							/* m_head2		*/
				hmsBegin()
					hmsSelect(0, CtrlMarioEye)							/* for the eye animation	*/
					hmsBegin()
						hmsGfx(RM_SURF, RCP_mario_head1)
						hmsGfx(RM_SURF, RCP_mario_head2)
						hmsGfx(RM_SURF, RCP_mario_head3)
						hmsGfx(RM_SURF, RCP_mario_head4)
						hmsGfx(RM_SURF, RCP_mario_head5)
						hmsGfx(RM_SURF, RCP_mario_head6)
						hmsGfx(RM_SURF, RCP_mario_head7)
						hmsGfx(RM_SURF, RCP_mario_head8)
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 67, -10, 79)							/* chn6			*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near2, 0, 0, 0)				/* m_larmA1		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near1, 65, 0, 0)			/* m_larmB1		*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near0, 60, 0, 0)		/* m_lhamd1		*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 68, -10, -79)						/* chn10		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near5, 0, 0, 0)				/* m_rarmA1		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near4, 65, 0, 0)			/* m_rarmB1		*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near3, 60, 0, 0)		/* m_rhand1		*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()

			hmsJoint(RM_SURF, NULL, 13, -8, 42)								/* chn15		*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_mario_near11, 0, 0, 0)					/* m_llegA1		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near10, 89, 0, 0)			/* m_llegB1		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near9, 67, 0, 0)			/* m_lfoot1		*/
					hmsEnd()
				hmsEnd()
			hmsEnd()

			hmsJoint(RM_SURF, NULL, 13, -8, -42)								/* chn17		*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_mario_near8, 0, 0, 0)					/* m_rlegA1		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near7, 89, 0, 0)				/* m_rlegB1		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near6, 67, 0, 0)			/* m_rfoot1		*/
					hmsEnd()
				hmsEnd()
			hmsEnd()

		hmsEnd()
	hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Near Mario hierarchy data.													*/
/********************************************************************************/

Hierarchy RCP_NearMarioHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 0, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_mario_near14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_mario_near_body, 68, 0, 0)					/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 87, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
						hmsRotate(0, 0, 0)								/* for control by program	*/
						hmsBegin()
							hmsSelect(1, geo_switch_mario_eyes /* TODO: CtrlMarioEye */)					/* for the eye animation	*/
							hmsBegin()
								hmsGfx(RM_SURF, RCP_mario_head1)
								hmsGfx(RM_SURF, RCP_mario_head2)
								hmsGfx(RM_SURF, RCP_mario_head3)
								hmsGfx(RM_SURF, RCP_mario_head4)
								hmsGfx(RM_SURF, RCP_mario_head5)
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 67, -10, 79)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near1, 65, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_mario_near0, 60, 0, 0)		/* m_lhamd1_2	*/
									hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
									hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 68, -10, -79)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near4, 65, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
							
								hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									// case 0
									hmsJoint(RM_SURF, RCP_mario_near3, 60, 0, 0)		/* m_rhand1_2	*/
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 1
									hmsJoint(RM_SURF, RCP_swim_hand_r, 60, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 2
									hmsJoint(RM_SURF, RCP_mario_vsign_hand, 60, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, 13, -8, 42)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near10, 89, 0, 0)			/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near9, 67, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 13, -8, -42)								/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_near8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_near7, 89, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_near6, 67, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Middle Mario hierarchy data.												*/
/********************************************************************************/

Hierarchy RCP_MidMarioHierarchy[] = {
		hmsJoint(RM_SURF, NULL, 0, 0, 0)									/* chn14_2_1	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_mario_mid14, 0, 0, 0)							/* m_waist1_3_2	*/
			hmsBegin()
				//hmsJoint(RM_SURF, RCP_mario_near_body, 68, 0, 0)						/* m_body1_2	*/
				hmsJoint(RM_SURF, RCP_mario_mid_body, 68, 0, 0)						/* m_body1_2	*/
				hmsBegin()

					hmsJoint(RM_SURF, NULL, 87, 0, 0)							/* m_head2		*/
					hmsBegin()
						hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
						hmsRotate(0, 0, 0)								/* for control by program	*/
						hmsBegin()
							hmsSelect(1, geo_switch_mario_eyes /* TODO: CtrlMarioEye */)					/* for the eye animation	*/
							hmsBegin()
								hmsGfx(RM_SURF, RCP_mario_head1)
								hmsGfx(RM_SURF, RCP_mario_head2)
								hmsGfx(RM_SURF, RCP_mario_head3)
								hmsGfx(RM_SURF, RCP_mario_head4)
								hmsGfx(RM_SURF, RCP_mario_head5)
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 67, -10, 79)							/* chn6			*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_mid2, 0, 0, 0)				/* m_larmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_mid1, 65, 0, 0)			/* m_larmB1_2	*/
							hmsBegin()
								hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_mario_mid0 , 60, 0, 0)		/* m_lhamd1_2	*/
									hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
									hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF, NULL, 68, -10, -79)						/* chn10		*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_mid5, 0, 0, 0)				/* m_rarmA1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_mid4, 65, 0, 0)			/* m_rarmB1_2	*/
							hmsBegin()
								hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
								hmsBegin()
									hmsJoint(RM_SURF, RCP_mario_mid3 , 60, 0, 0)		/* m_rhand1_2	*/
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									hmsJoint(RM_SURF, RCP_swim_hand_r, 60, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
									// case 2
									hmsJoint(RM_SURF, RCP_mario_vsign_hand, 60, 0, 0)
									hmsBegin()
										hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
									hmsEnd()
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()

				hmsEnd()

				hmsJoint(RM_SURF, NULL, 13, -8, 42)								/* chn15		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_mid11, 0, 0, 0)					/* m_llegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_mid10, 89, 0, 0)				/* m_llegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_mid9, 67, 0, 0)			/* m_lfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 13, -8, -42)								/* chn17		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_mid8, 0, 0, 0)					/* m_rlegA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_mid7, 89, 0, 0)				/* m_rlegB1_2	*/
						hmsBegin()
							hmsJoint(RM_SURF, RCP_mario_mid6, 67, 0, 0)			/* m_rfoot1_2	*/
						hmsEnd()
					hmsEnd()
				hmsEnd()

			hmsEnd()
		hmsEnd()
	hmsReturn()
};
/********************************************************************************/
/*	Far Mario hierarchy data.													*/
/********************************************************************************/

Hierarchy RCP_FarMarioHierarchy[] = {
	hmsJoint(RM_SURF, NULL, 0, 0, 0)									/* chn14_2_1	*/
	hmsBegin()
		hmsJoint(RM_SURF, RCP_mario_far14, 0, 0, 0)							/* m_waist1_3_2	*/
		hmsBegin()
			hmsJoint(RM_SURF, RCP_mario_far_body, 68, 0, 0)						/* m_body1_2	*/
			hmsBegin()

				hmsJoint(RM_SURF, NULL, 87, 0, 0)							/* m_head2		*/
				hmsBegin()
					hmsCProg(1, geo_mario_head_rotation /* TODO: CtrlMarioHead */)
					hmsRotate(0, 0, 0)								/* for control by program	*/
					hmsBegin()
						hmsSelect(1, geo_switch_mario_eyes /* TODO: CtrlMarioEye */)					/* for the eye animation	*/
						hmsBegin()
							hmsGfx(RM_SURF, RCP_mario_far_head1)
							hmsGfx(RM_SURF, RCP_mario_far_head2)
							hmsGfx(RM_SURF, RCP_mario_far_head3)
							hmsGfx(RM_SURF, RCP_mario_far_head4)
							hmsGfx(RM_SURF, RCP_mario_far_head5)
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 67, -10, 79)							/* chn6			*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_far2, 0, 0, 0)				/* m_larmA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_far1, 65, 0, 0)			/* m_larmB1_2	*/
						hmsBegin()
							hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
							hmsBegin()
								hmsJoint(RM_SURF, RCP_mario_far0 , 60, 0, 0)		/* m_lhamd1_2	*/
								hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
								hmsJoint(RM_SURF, RCP_swim_hand_l, 60, 0, 0)
							hmsEnd()
						hmsEnd()
					hmsEnd()
				hmsEnd()

				hmsJoint(RM_SURF, NULL, 68, -10, -79)						/* chn10		*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_far5, 0, 0, 0)				/* m_rarmA1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_far4, 65, 0, 0)			/* m_rarmB1_2	*/
						hmsBegin()
							hmsSelect(0, geo_switch_mario_hand /* TODO: CtrlMarioHand */)
							hmsBegin()
								hmsJoint(RM_SURF, RCP_mario_far3 , 60, 0, 0)		/* m_rhand1_2	*/
								hmsBegin()
									hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
								hmsEnd()
								hmsJoint(RM_SURF, RCP_swim_hand_r, 60, 0, 0)
								hmsBegin()
									hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
								hmsEnd()
								// case 2
								hmsJoint(RM_SURF, RCP_mario_vsign_hand, 60, 0, 0)
								hmsBegin()
									hmsSucker(0,0,0, 1,geo_switch_mario_hand_grab_pos /* TODO: CtrlMarioTaking */)
								hmsEnd()
							hmsEnd()
						hmsEnd()
					hmsEnd()
				hmsEnd()

			//hmsEnd()

			hmsJoint(RM_SURF, NULL, 13, -8, 42)								/* chn15		*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_mario_far11, 0, 0, 0)					/* m_llegA1_2	*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_far10, 98, 0, 0)				/* m_llegB1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_far9, 81, 0, 0)			/* m_lfoot1_2	*/
					hmsEnd()
				hmsEnd()
			hmsEnd()
			
			hmsJoint(RM_SURF, NULL, 13, -8, -42)								/* chn17		*/
			hmsBegin()
				hmsJoint(RM_SURF, RCP_mario_far8, 0, 0, 0)					/* m_rlegA1_2	*/
				hmsBegin()
					hmsJoint(RM_SURF, RCP_mario_far7, 89, 0, 0)				/* m_rlegB1_2	*/
					hmsBegin()
						hmsJoint(RM_SURF, RCP_mario_far6, 67, 0, 0)			/* m_rfoot1_2	*/
					hmsEnd()
				hmsEnd()
			hmsEnd()

		hmsEnd()
	hmsEnd()
	hmsReturn()
};

/********************************************************************************/
/*	Mario hierarchy map data.													*/
/********************************************************************************/

Hierarchy RCP_MarioHierarchy[] = {
	//GEO_NODE_START(),
 	hmsShadow(100, 180, 99)
	hmsBegin()
		hmsScale(0.25f)
		hmsBegin()
			hmsSelect(1, geo_switch_mario_hand /* TODO: CtrlMarioLOD */)
			hmsBegin()
				//hmsCall(RCP_NearMarioHierarchy)
				hmsGroup()
				hmsBegin()
					hmsLOD(-2048,600)
					hmsBegin()
						hmsCall(RCP_NearMarioHierarchy)
					hmsEnd()

					hmsLOD(600,1600)
					hmsBegin()
						hmsCall(RCP_MidMarioHierarchy)
					hmsEnd()

					hmsLOD(1600,32767)
					hmsBegin()
					    hmsCall(RCP_FarMarioHierarchy)
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

Hierarchy RCP_TitleMario[] = {
 	hmsShadow(100, 180, 99)
	hmsBegin()
		hmsScale(0.25f)
		hmsBegin()
			hmsCall(RCP_TitleMarioHierarchy)
		hmsEnd()
	hmsEnd()
	hmsReturn() // was hmsExit()
};