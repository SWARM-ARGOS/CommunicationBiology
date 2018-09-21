#include "stdafx.h"


void Envi_Dynamics(void){//Object�̃_�C�i�~�N�X
	int i, p;
	double T_x		= 0;									//Food�ɓ������i�̗�
	double T_y		= 0;
	double R		= 0;									//Food�ɓ�����]�̗�
	double ang_T	= 0;
	double I		= food_mass * pow(Food_scale, 2) / 2;
	double fri_pf	= Fri_o_f * food_mass * G;				//Food��Field�̖��C��

	//Food�̗͂̏�����
	for(p = 0; p < foods; p++){
		food[p].Food_T		= 0;
		food[p].Food_Tx		= 0;
		food[p].Food_Ty		= 0;
		food[p].Food_ang	= 0;
		food[p].ang_r		= 0;
		food[p].Food_R		= 0;
	}

	#pragma omp parallel for
	for(i = 0; i < robots; i++){
		if(robot[i].Food_ID != 9999 || robot[i].aSA_ID != 9999){
			sa[robot[i].SA_root].sa_x	=	0;
			sa[robot[i].SA_root].sa_y	=	0;

			robot[i].ang_nest = atan2(nest_y - robot[i].y, nest_x - robot[i].x);
			
			//Robot��SA�͊w�v�Z
			//SA�����G�[�W�F���g�̗͂�Root-SA�Ɂ{
			sa[robot[i].SA_root].sa_x += AGENT_F * cos(robot[i].ang_nest);
			//SA�����G�[�W�F���g�̗͂�Root-SA�Ɂ{
			sa[robot[i].SA_root].sa_y += AGENT_F * sin(robot[i].ang_nest);
			sa[robot[i].SA_root].ang_r = atan2(sa[robot[i].SA_root].sa_y, sa[robot[i].SA_root].sa_x);

			//RootSA robot�ɂ܂Ƃ߂�
			robot[robot[i].SA_root].ang_NL = atan2(robot[robot[i].SA_root].y - food[robot[robot[i].SA_root].Food_ID].y, robot[robot[i].SA_root].x - food[robot[robot[i].SA_root].Food_ID].x);
			robot[robot[i].SA_root].F = sqrt(pow(sa[robot[i].SA_root].sa_x, 2) + pow(sa[robot[i].SA_root].sa_y, 2));
			robot[robot[i].SA_root].Ft = robot[robot[i].SA_root].F * sin(sa[robot[i].SA_root].ang_r - robot[robot[i].SA_root].ang_NL);

			//Food�̗͊w�v�Z�i���i�j
			food[robot[robot[i].SA_root].Food_ID].Food_Tx	+=	sa[robot[i].SA_root].sa_x;
			food[robot[robot[i].SA_root].Food_ID].Food_Ty	+=	sa[robot[i].SA_root].sa_y;
			food[robot[robot[i].SA_root].Food_ID].Food_T	=	sqrt(pow(food[robot[robot[i].SA_root].Food_ID].Food_Tx, 2) + pow(food[robot[robot[i].SA_root].Food_ID].Food_Ty, 2));
			food[robot[robot[i].SA_root].Food_ID].Food_ang	=	atan2(food[robot[robot[i].SA_root].Food_ID].Food_Ty , food[robot[robot[i].SA_root].Food_ID].Food_Tx);
			//Food�̗͊w�v�Z�i��]�j
			food[robot[robot[i].SA_root].Food_ID].Food_R	+=	robot[robot[i].SA_root].Ft;
		}		
	}

	for (p = 0; p < foods; p++){
		if(fabs(fri_pf) < fabs(food[p].Food_T)){
			//Transrarion
			T_x	= food[p].Food_Tx - fri_pf * cos(food[p].Food_ang);
			T_y = food[p].Food_Ty - fri_pf * sin(food[p].Food_ang);
			
			if(sqrt(pow(T_x, 2) + pow(T_y, 2)) > robot_v){
				T_x = robot_v * cos(food[p].Food_ang);
				T_y = robot_v * sin(food[p].Food_ang);
			}
			food[p].dx = T_x * pow(dt, 2);
			food[p].dy = T_y * pow(dt, 2);
			food[p].x += food[p].dx;
			food[p].y += food[p].dy;

			//Rotation
			R = food[p].Food_R * Food_scale;
			food[p].ang_r = R / I / dt;
			food[p].ang_d += food[p].ang_r * 180 / M_PI;
		}	
	}
}
