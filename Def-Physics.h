//�����萔
#ifndef dt			//�P�ʎ���
#define dt			0.1
#endif
#ifndef G			//�d�͉����x
#define G			9.8
#endif
#ifndef M_PI		//�~����
#define M_PI		3.14159265358979323846
#endif
#ifndef GRID_SPAN	//�O���b�h�Ԋu
#define GRID_SPAN	2
#endif
#ifndef T			//���݂̃X�e�b�v
#define T			0
#endif
#ifndef T_1			//t-1�X�e�b�v
#define T_1			1
#endif
#ifndef COE_EVA		//�����W��
#define COE_EVA		0.999
#endif
#ifndef COE_DIF		//�g�U�W��
#define COE_DIF		0.001
#endif
#ifndef Fri_o_f		//Food��Field�Ԃ̖��C�W��
#define Fri_o_f		0.5
#endif
#ifndef TimeLimit	//�������E����
#define TimeLimit	12000
#endif


//Robot�̒萔
#ifndef AGENT_mass	
#define AGENT_mass	1.5			//Robot�̎���[kg]
#endif
#ifndef ADD_P
#define ADD_P		100			//�Y���t�F��������
#endif
#ifndef TMR_PULL
#define TMR_PULL	5			//Pull�҂�����[sec]
#endif
#ifndef TMR_SA
#define TMR_SA		100			//SA�҂�����[sec]
#endif
#ifndef TMR_AT
#define TMR_AT		100			//�U������[sec]
#endif
#ifndef AGENT_F
#define AGENT_F		0.75		//Robot�̒P�ʏo��[N]
#endif
#ifndef AGENT_V
#define AGENT_V		10			//Robot�̒P�ʑ��x(AGENT_V)[cm/sec]
#endif
//#ifndef P_Det
//#define P_Det		2.274776	//�t�F�������̍Œጟ�o��
//#endif
#ifndef P_Det
#define P_Det		68.678207	//�t�F�������̍Œጟ�o��
#endif


//Environment�̒萔
#ifndef WIDTH
#define WIDTH		900//Field�̕�[cm]
#endif
#ifndef HEIGHT
#define HEIGHT		90//Field�̍���(���s��)[cm]
#endif


#ifndef G1_div
#define G1_div		20//Nest�̕�����
#endif
#ifndef G1_scale	//Nest�̃T�C�Y
#define G1_scale	60//���a[cm]
#endif
#ifndef G2_div		//Food�̖ړI�n�̕�����
#define G2_div		20
#endif
#ifndef G2_scale	//Food�̖ړI�n�̃T�C�Y
#define G2_scale	100//���a[cm]
#endif


//Foods
#ifndef Food_scale	//Food�X�P�[��
#define Food_scale	26//���a[cm]
#endif
//#ifndef Food_scale	//Food�X�P�[��
//#define Food_scale	16//���a[cm]
//#endif
#ifndef Food_div	//�~�̕�����
#define Food_div	20
#endif
