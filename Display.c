#include "stdafx.h"
#pragma warning(disable:4996)

void draw_text(void){
	int i;
	char str[256];

	sprintf(str, "%d", step / 10/*food[0].ang_d*/);

	glColor3d(0.0, 0.0, 0.0);
	glPushMatrix();
		glTranslated(0.0, -20.0, 0.0);
		glRotated(0.0, 0.0, 0.0, 1.0);
		glScalef(0.1, 0.1, 1.0);
		for(i = 0; str[i] != '\0' ; i++){
			glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
		}
	glPopMatrix();
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Window��h��Ԃ�
	glLoadIdentity();
	
	gluLookAt(WIDTH, -WIDTH, WIDTH + view_z, WIDTH/2, HEIGHT/2, 0.0, 0.0, 0.0, 1.0);//���_�̐ݒ�
	
	//Draw�֐��̌Ăяo��
	draw_field();			//Field��`��(���𓖂ĂȂ�)
	draw_pheromone();		//Pheromone��`��(���𓖂ĂȂ�)
	draw_robot();			//Robot��`��
	draw_robotvector();		//Robot�̐i�s�����̕\��
	draw_robot_number();
	draw_food();			//Food�̕`��
	draw_text();			//Step���̕\��
	draw_nest1();			//Nest

	glutSwapBuffers();		//�_�u���o�b�t�@
}
