#ifndef STRUCTURE_AND_DEFINE
#define STRUCTURE_AND_DEFINE

//�\���̂̒�`
#include "struct.h"

//�萔�̐ݒ�
#include "Def-Physics.h"

//�O���[�o���ϐ�
extern int gen;
extern int trial;
extern int argos;
extern int swarm;
extern int draw;
extern int idle_f;
extern int robots;
extern int foods;
extern int food_mass;
extern int food_dis;
extern double p_density;
extern int opposite;
extern int foodlimit;
extern int foodcount;
extern double collision_rand;
extern double P_p_rand;
extern double P_p[9999999];
extern double collision[9999999][3];
extern double scale_argos;

extern int nest_x;
extern int nest_y;


extern int step;		//�X�e�b�v���̕\��
extern int t;
extern int t_1;
extern int view_z;		//���_��Z������
extern int act_trace;
extern double robot_v;
extern double c_eva;	//�����W��
extern double dif;		//�g�U�W��
extern int dA_p;
extern int dF_p;
extern char dir_name[1000];
extern FILE *State_log;
extern FILE *result;


//Log
extern int Lay_down_a;					//Food_a�̕~�݉�
extern int Reinforce_a;					//Food_a�̋�����
extern int Lay_down_b;					//Food_b�̕~�݉�
extern int Reinforce_b;					//Food_b�̋�����
extern unsigned long Collision_total;	//�Փˉ񐔂̃J�E���g

//�z��i���v�Z�j
extern Robot robot[1000];									//Robot�����̔z��̍쐬
extern Robot_mem robot_mem[1000];							//Robot�����̔z��̍쐬
extern SA sa[100];
extern P_grid1 p_grid1[WIDTH][HEIGHT][2];					//Field���Z���ɕ�������
extern P_grid2 p_grid2[WIDTH/GRID_SPAN][HEIGHT/GRID_SPAN];	//Field���Z���ɕ�������
extern Food food[100];										//Food�̍\����

////�z��iLog�ۑ��j
//extern Robot_Log robot_log[1000][TimeLimit];
extern Food_Log food_log[100][TimeLimit];
extern int state_log[TimeLimit][1000];


#endif
