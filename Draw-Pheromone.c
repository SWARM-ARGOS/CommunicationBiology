#include "stdafx.h"



void draw_pheromone(void)
{
	//�錾
	int i, j, k, l;


	//Pheromone�̉����v�Z
	for (i = 0; i < WIDTH / GRID_SPAN; i++){
		for (j = 0; j < HEIGHT / GRID_SPAN; j++){
			p_grid2[i][j].F_p = 0;
			p_grid2[i][j].A_p = 0;
			for (k = 0; k < GRID_SPAN; k++){
				for (l = 0; l < GRID_SPAN; l++){
					p_grid2[i][j].F_p	+=	p_grid1[GRID_SPAN*i+k][GRID_SPAN*j+l][t].F_p;
					p_grid2[i][j].A_p	+=	p_grid1[GRID_SPAN*i+k][GRID_SPAN*j+l][t].A_p;
				}
			}
		}
	}
	
	glDisable(GL_LIGHTING);

	//�n�\��Pheromone
	if(dF_p == TRUE){
		glColor3d(1.0, 0.0, 0.0);//�t�F�������̐F�̐ݒ�
		//F_p�̕`��
		glBegin(GL_LINES);
		for (i = 0; i < WIDTH / GRID_SPAN - 1; ++i){//x�������̐�
			for (j = 0; j < HEIGHT / GRID_SPAN; ++j){
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].F_p / 50);
				glVertex3d(GRID_SPAN*(i+1) + GRID_SPAN/2,	GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i+1][j].F_p / 50);
			}
		}
		glEnd();

		glBegin(GL_LINES);
		for (j = 0; j < HEIGHT / GRID_SPAN - 1; ++j){//y�������̐�
			for (i = 0; i < WIDTH / GRID_SPAN; ++i){
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].F_p / 50);
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*(j+1) + GRID_SPAN/2,	p_grid2[i][j+1].F_p / 50);
			}
		}
		glEnd();
	}
	
	////��C����Pheromone
	//if(dA_p == TRUE){
	//	glColor3d(1.0, 0.0, 0.0);//�t�F�������̐F�̐ݒ�
	//	//A_p�̕`��
	//	glBegin(GL_LINES);
	//	for(i = 0; i < WIDTH / GRID_SPAN - 1; ++i){//x�������̐�
	//		for(j = 0; j < HEIGHT / GRID_SPAN; ++j){
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].A_p / 2);
	//			glVertex3d(GRID_SPAN*(i+1) + GRID_SPAN/2,	GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i+1][j].A_p / 2);
	//		}
	//	}
	//	glEnd();

	//	glBegin(GL_LINES);
	//	for(j = 0; j < HEIGHT / GRID_SPAN - 1; ++j){//y�������̐�
	//		for(i = 0; i < WIDTH / GRID_SPAN; ++i){
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].A_p / 2);
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*(j+1) + GRID_SPAN/2,	p_grid2[i][j+1].A_p / 2);
	//		}
	//	}
	//	glEnd();
	//}

	glEnable(GL_LIGHTING);
}
