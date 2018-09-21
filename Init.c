#include "stdafx.h"


void init_argos(void){
	if(argos == FALSE)
		scale_argos = 11.5;
	else if(argos == TRUE)
		scale_argos = 7.5;
}


void init_robot(void){
	//�錾
	int i;

	robot_v = AGENT_V * dt;

	srand((unsigned)time(NULL));

	//Robot�̏�����
	//#pragma omp parallel for
	for(i = 0; i < robots; ++i)	{
		//���W
		robot[i].x			=	rand() / (RAND_MAX + 1.0) * WIDTH;
		robot[i].y			=	rand() / (RAND_MAX + 1.0) * HEIGHT;
//		robot[i].x			=	0;
//		robot[i].y			=	HEIGHT / 2;
		robot[i].dx			=	0;
		robot[i].dy			=	0;
		//�p�x
		robot[i].ang_r		=	rand() / (RAND_MAX + 1.0) * 2 * M_PI;
		robot[i].ang_d		=	0;
		robot[i].ang_NL		=	0;
		robot[i].ang_OA		=	0;
		//���̑�
		robot[i].state		=	1;
		robot[i].aSA_ID		=	9999;
		robot[i].Food_ID	=	9999;
		robot[i].SA_root	=	9999;

		robot[i].flag_phe_l = FALSE;
		robot[i].flag_phe_r = FALSE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
		robot[i].count_collision = 0;
	}
}


void init_food(void){
	int p;

	for(p = 0; p < foods; p++){
		food[p].dx		=	0;
		food[p].dy		=	0;
		food[p].ang_d	=	0;
		food[p].ang_r	=	0;
		food[p].dis		=	0;
		food[p].state	=	0;
	}
	if(opposite == 0){
		food[0].x		=	WIDTH - Food_scale;
		food[0].y		=	HEIGHT/2;
	}
	else if(opposite == 1){
		food[0].x		=	WIDTH - Food_scale;
		food[0].y		=	HEIGHT - Food_scale;
	}
}


void init_nest(void){
	if(opposite == 0){
		nest_x		=	0;
		nest_y		=	HEIGHT/2;
	}
	else if(opposite == 1){
		nest_x		=	0;
		nest_y		=	0;
	}
}


void init_pheromone(void){
	//�錾
	int i;
	int j;
	
	dF_p = FALSE;
	dA_p = FALSE;

	//�t�F�������̏�����
	for(i = 0; i < WIDTH; ++i){	
		for(j = 0; j < HEIGHT; ++j){
			p_grid1[i][j][T].F_p = 0;
			p_grid1[i][j][T].A_p = 0;
			p_grid1[i][j][T_1].F_p = 0;
			p_grid1[i][j][T_1].A_p = 0;
		}
	}

	//�t�F�������̏�����	
	for(i = 0; i < WIDTH / GRID_SPAN; ++i){
		for(j = 0; j < GRID_SPAN; ++j){
			p_grid2[i][j].F_p = 0;
			p_grid2[i][j].A_p = 0;
		}
	}
}


void init_eva_dif(void){
	double eva;

	//�����W���̌���
	eva		= -0.0443 * pow(p_density, 2) + 0.0039 * p_density + 0.993;
	c_eva	= 1 - ((1 - eva) / (10 / dt));	//������10�b�P��
	
	//�g�U�W���̌���
	dif		= (p_density * COE_DIF) / 0.4;
}


void init_setting(void){
	//���Ɣ��˂̏�����
	GLfloat light_position0[] = {0.0,	0.0,	500.0,	0.0};//�����ʒu�i�P�j
	GLfloat light_position1[] = {WIDTH, HEIGHT,	500.0,	0.0};//�����ʒu�i�Q�j

	//Window��h��Ԃ����̐F�̎w��
	glClearColor(1.0, 1.0, 1.0, 0.0);

	//������
	step = 0;		//�X�e�b�v�̏�����
	
	//�`��
	if(WIDTH == 180)
		view_z = 300;
	if(WIDTH == 360)
		view_z = 500;
	if(WIDTH == 540)
		view_z = 700;
	if(WIDTH == 720)
		view_z = 900;
	if(WIDTH == 900)
		view_z = 1200;

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	//��
	glEnable(GL_LIGHTING);						//����������悤�ɂ���
	glEnable(GL_LIGHT0);						//���C�g0��L���ɂ���
	glEnable(GL_LIGHT1);						//���C�g1��L���ɂ���
	glEnable(GL_COLOR_MATERIAL);				//�ގ��p�����[�^�����݂̃J���[�ɒǏ]
	
	//�B�ʏ���
	glEnable(GL_DEPTH_TEST);					//�f�v�X�e�X�g��L���ɂ���
	glDepthFunc(GL_LEQUAL);
	
	//��������
	glEnable(GL_BLEND);							//��������
		
	//�@���̎Z�o
	glEnable(GL_NORMALIZE);						//�@���̐��K��
}


void init_log(void){
	int i, j, p;
	
	//Robot-Log�̏�����
	//#pragma omp parallel for
	//for(i = 0; i < robots; i++){
	//	#pragma omp parallel for
	//	for(j = 0; j < TimeLimit; j++){
	//		//���W
	//		robot_log[i][j].step	= 0;
	//		robot_log[i][j].x		= 0;
	//		robot_log[i][j].y		= 0;
	//		robot_log[i][j].ang_r	= 0;
	//		robot_log[i][j].state	= 0;
	//	}
	//}

	//Food-Log�̏�����
	for(p = 0; p < foods; p++){
		for(j = 0; j < TimeLimit; j++){
			//���W
			food_log[p][j].step		= 0;
			food_log[p][j].x		= 0;
			food_log[p][j].y		= 0;
			food_log[p][j].dis		= 0;
			food_log[p][j].state	= 0;
		}
	}
}


void init(void){
	idle_f = TRUE;
	foodcount = 0;
	Lay_down_a = 0;					//�~�݉�
	Reinforce_a = 0;				//������
	Lay_down_b = 0;					//�~�݉�
	Reinforce_b = 0;				//������
	Collision_total = 0;			//�Փˉ񐔂̏�����

	srand((unsigned)time(NULL));
	init_argos();
	init_robot();
	init_food();
	init_nest();
	init_pheromone();
	init_eva_dif();
	init_log();
	init_setting();
}