#include "stdafx.h"
#pragma warning(disable:4996)

void draw_robot(void){//Robot�̕`��
	//�錾
	int i;
	
	for(i = 0; i < robots; ++i){
		//�F�̐ݒ�
		if(robot[i].state == 1){
			glColor3d(1.0, 0.0, 0.0);//���b�h
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//�C�G���[
		}
		if(robot[i].state == 2){
			glColor3d(0.0, 1.0, 0.0);//�O���[��
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//�C�G���[
		}
		if(robot[i].state == 3){
			glColor3d(0.0, 0.0, 1.0);//�u���[
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//�C�G���[
		}

		glPushMatrix();
			glTranslated(robot[i].x, robot[i].y, 4.0);	//���i
			glRotated(robot[i].ang_d, 0.0, 0.0, 1.0);	//��]
			glRotated(90.0, 1.0, 0.0, 0.0);				//Z�������
			glutSolidTeapot(scale_argos);				//Teapot��`��
		glPopMatrix();
	}
}

void draw_robotvector(void){
	//�錾
	int i;

	//�ݒ�
	glDisable(GL_LIGHTING);

	//Field�̕`��
	glColor4d(0.0, 0.0, 0.0, 1.0);//���ꂩ��`�悷����̂̐F���w��

	for (i = 0; i < robots; i++){
		glBegin(GL_LINES);
			glVertex3d(robot[i].x, robot[i].y, scale_argos * 2);	//x������
			glVertex3d(robot[i].x + 5 * 4*robot[i].dx, robot[i].y + 5 * 4*robot[i].dy, scale_argos * 2);
		glEnd();
	}
	glFlush();
}


void draw_robot_number(void)
{
	int i, j;
	char str[256];

	for (i = 0; i < robots; i++){
		sprintf(str, "%d", i);

		glColor3d(0.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(robot[i].x, robot[i].y, 10.0);
			glRotated(0.0, 0.0, 0.0, 1.0);
			glScalef(0.05, 0.05, 3.0);

			for (j = 0; str[j] != '\0'; j++)
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[j]);
		glPopMatrix();
	}
}