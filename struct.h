//////////////////////////////////////////
//Robot�̕ϐ��̐ݒ�
//////////////////////////////////////////
typedef struct{
	//Robot�̐���
	int state;				//�������

	//Robot�̍��W�E���x�E��
	int	grid_x, grid_y;		//�Z���ʒu
	double x, y;			//���W
	double dx, dy;			//���x�x�N�g��
	double F;
	double Fn, Fnx, Fny;
	double Ft;
	
	//Robot�̊p�x
	double ang_d;			//Robot�̌����Ă������(Degree)
	double ang_r;			//Robot�̌����Ă������(radian)
	double ang_dr;			//�����p�x
	double ang_go;			//���ۂ�Robot�̐i�s����

	//Robot�Ƒ��̊p�x
	double ang_NL;			//Food�ƐڐG�����Ƃ��̖@������
	double ang_OA;			//ang_NL�̋t�A�~���̏d�S���猩��Robot�̊p�x
	double ang_nest;		//Nest�̕���
	double ang_ij;			//�ڐG�����̂̕���
	double ang_OS;			//�Փ˂����q�̂̕����iRobot�̐i�s�����ɑ΂��āj
	double ang_col;

	//�m�o�W��
	int p_touch_food;		//Food�ڐG�m�o�W��
	int p_arrival_nest;		//Nest�����m�o�W��
	int p_phero_L;			//�t�F�������m�o�W��
	int p_phero_R;			//�t�F�������m�o�W��
	int p_sc_timer;			//�����^�C�}�[
	int p_lay_miss;			//�~�ݎ��s�̒m�o�W��

	//���̑�
	int aSA_ID;				//SA���Ă��鑊���ID
	int Food_ID;			//�c�����Ă���Food��ID
	int SA_root;			//Root robot��ID
	int grip;				//Food��Robot��͂�ł���
	int grip_Robot;			//Robot��͂�ł���
	int grip_Food;			//Food��͂�ł���
	double dis_pot;			//���̂Ƃ̋���
	
	//Counter
	int random;								//���������i0�|99�j
	int count_RW;							//RW�J�E���^
	int count_p_trace;						//�t�F�������Ǐ]�J�E���^
	int count_collision;					//�Փˏ����J�E���^
	int count_lay_failure;					//�~�ݒ�~�J�E���^
	int count_move;							//�^���J�E���^

	//Flag
	int flag_RW;							//RW�̃t���O
	int flag_phe_l, flag_phe_r, flag_phe_b;	//�s���J�n�E��~�t���O

	//�Փ˔���
	int colli_robot;
	int colli_wall;
	int colli_food;

	//�t�F�������Z���T�[
	double L_sensor, R_sensor;		//�t�F�������Z���T�[

	//Pheromone�����t���O
	int f_laydown_a;				//�~�݃t���O(S1��S2)
	int f_reinforce_a;				//�����t���O1(S1��S3)
	int f_laydown_b;				//�~�݃t���O(S1��S2)
	int f_reinforce_b;				//�����t���O1(S1��S3)

	FILE *Log;
} Robot;


//////////////////////////////////////////
//Robot_mem�̍\����
//////////////////////////////////////////
typedef struct {
	double dx_mem1, dy_mem1;		//1�X�e�b�v�œ��������i���x�j
	double dx_mem2, dy_mem2;		//1�X�e�b�v�œ��������i���x�j
	double ang_r_mem1, ang_r_mem2;	//�p�x�idegree�j

	FILE *Log;
} Robot_mem;


//////////////////////////////////////////
//Food�̍\����
//////////////////////////////////////////
typedef struct {
	double x, y;			//���W
	double dx, dy;			//1�X�e�b�v�œ��������i���x�j
	double ang_d;			//�p�x�iradian�j
	double ang_r;			//�p�x�idegree�j
	double dis;
	int state;

	double Food_Tx;			//X�������̗́i���i�j
	double Food_Ty;			//Y�������̗́i���i�j
	double Food_T;			//���i��
	double Food_ang;		//���i�̊p�x
	double Food_R;			//

	FILE *Log;
} Food;


//////////////////////////////////////////
//Nest�̍\����
//////////////////////////////////////////
typedef struct {
	int nest_x;
	int nest_y;
	int nest_div;
	int nest_scale;
} Nest;


//////////////////////////////////////////
//SA�v�Z�̍\����
//////////////////////////////////////////
typedef struct
{
	double sa;
	double sa_x;
	double sa_y;
	double ang_r;
} SA;



//////////////////////////////////////////
//Log
//////////////////////////////////////////
//typedef struct{
//	int step;
//	double x;
//	double y;
//	double ang_r;
//	int state;
//} Robot_Log;


typedef struct{
	int step;
	double x;
	double y;
	double dis;
	int state;
} Food_Log;


typedef struct{//���ۂ�Field��Grid�̕ϐ��̐ݒ�
	double F_p;		//�n��̃t�F������
	double A_p;		//��C���̃t�F������
	double P_dif;	//���͂���g�U���Ă���t�F������
} P_grid1;



typedef struct{//Display�p��Field��Grid�̕ϐ��̐ݒ�
	double F_p;		//�n��̃t�F������
	double A_p;		//��C���̃t�F������
} P_grid2;

