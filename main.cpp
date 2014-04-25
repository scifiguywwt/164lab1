/* Max Savage/Adam Wells Minigolf Rendering
  , atwells@ucsc.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "util.h"
#include <time.h>
#include <math.h>


void drawTile(float tile[]) {
	glBegin(GL_POLYGON);
	glColor3f(0, 255, 0);
	//printf("Made it here.");
	printf("TILE ID = %i\n", (int)tile[0]);
	printf("LENGTH = %i\n", (int)(4*tile[1]+2));

	for(int i = 2, length = 4*tile[1] + 2; i < length - tile[1]; i += 3) {
		glVertex3f(tile[i], tile[i+1], tile[i+2]);
		printf("X VALUE = %4.2f Y VALUE = %4.2f Z VALUE = %4.2f\n", tile[i], tile[i+1], tile[i+2]);		
	}
	
	float normals[3][3];
	for(int i = 2; i<5; i++){
		normals[0][i-2] = tile[i];
	}
	for(int i = 5; i < 8; i++) {
		normals[1][i-5] = tile[i];
	}
	for(int i = 8; i < 11; i++) {
		normals[2][i-8] = tile[i];
	}
	
	float xNorm, yNorm, zNorm;
	float ax, bx, ay, by, az, bz;
	ax = normals[1][0] - normals[0][0];
	ay = normals[1][1] - normals[0][1];
	az = normals[1][2] - normals[0][2];
	
	bx = normals[2][0] - normals[0][0];
	by = normals[2][1] - normals[0][1];
	bz = normals[2][2] - normals[0][2];
	
	xNorm = ay*bz - az*by;
	yNorm = ax*bz - az*bx;
	zNorm = ax*by - ay*bx;
	
	glNormal3d(xNorm, yNorm, zNorm);
	
	glEnd();
	glFlush();
	
}

void drawTee(float tee[]) {
	glBegin(GL_QUADS);
	glColor3f(255, 0, 0);
	glVertex3f(tee[1]+.1, tee[2]+.01, tee[3]+.1);
	glVertex3f(tee[1]+.1, tee[2]+.01, tee[3]-.1);
	glVertex3f(tee[1]-.1, tee[2]+.01, tee[3]-.1);
	glVertex3f(tee[1]-.1, tee[2]+.01, tee[3]+.1);
	glEnd();
	glFlush();

}

void drawCup(float cup[]) {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex3f(cup[1]+.1, cup[2]+.01, cup[3]+.1);
	glVertex3f(cup[1]+.1, cup[2]+.01, cup[3]-.1);
	glVertex3f(cup[1]-.1, cup[2]+.01, cup[3]-.1);
	glVertex3f(cup[1]-.1, cup[2]+.01, cup[3]+.1);
	glEnd();
	glFlush();
}

void cb_keyboard(unsigned char key, int x, int y) {
	// Add controls to animation, joint movement control, etc.
	// Some camera functions are provided for model viewing convinience.
	switch(key) {
		case '1':
			set_cam(DEFAULT);
			break;
		case '2':
			set_cam(FRONT);
			break;
		case '3':
			set_cam(SIDE);
			break;
		case '4':
			set_cam(TOP);
			break;
		case '5':
			set_cam(ANGLE);
			break;
		case ' ':
			set_cam(STOP);
			break;

		case 's':
			set_cam(BACKUP);
			break;
		case 'w':
			set_cam(GOFORWARD);
			break;
		case 'a':
			set_cam(LEFT);
			break;
		case 'd':
			set_cam(RIGHT);
			break;
		case 'f':
			set_cam(UP);
			break;
		case 'r':
			set_cam(DOWN);
			break;
			
		case 'i':
			set_cam(ROTUP);
			break;
		case 'k':
			set_cam(ROTDOWN);
			break;
		case 'j':
			set_cam(ROTLEFT);
			break;
		case 'l':
			set_cam(ROTRIGHT);
			break;

		case 'q':
			exit(0);
			break;
			


	}
}

void cb_reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawlevel2() {
	float tile1[] = {1, 5, -2.5, 0, 2.5, -0.5, 0, 2.5, -0.5, 0, 1.5, -1.5, 0, 0.5, -2.5, 0, 0.5, 0, 2, 4, 7, 0};
	float tile2[] = {2, 4, -0.5, 0, 2.5, 0.5, 0, 2.5, 0.5, 0, 1.5, -0.5, 0, 1.5, 0, 3, 5, 1};
	float tile3[] = {3, 5, 0.5, 0, 2.5, 2.5, 0, 2.5, 2.5, 0, 0.5, 1.5, 0, 0.5, 0.5, 0, 1.5, 0, 0, 11, 6, 2};
	float tile4[] = {4, 3, -0.5, 0, 1.5, -0.5, 0.5, 0.5, -1.5, 0, 0.5, 5, 8, 1};
	float tile5[] = {5, 4, -0.5, 0, 1.5, 0.5, 0, 1.5, 0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 2, 6, 9, 4};
	float tile6[] = {6, 3, 0.5, 0, 1.5, 1.5, 0.0, 0.5, 0.5, 0.5, 0.5, 3, 10, 5};
	float tile7[] = {7, 4, -2.5, 0, 0.5, -1.5, 0, 0.5, -1.5, 0, -0.5, -2.5, 0, -0.5, 1, 8, 15, 0};
	float tile8[] = {8, 4, -1.5, 0, 0.5, -0.5, 0.5, 0.5, -0.5, 0.5, -0.5, -1.5, 0, -0.5, 4, 9, 12, 7};
	float tile9[] = {9, 4, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, 0.5, -0.5, 5, 10, 13, 8};
	float tile10[] = {10, 4, 0.5, 0.5, 0.5, 1.5, 0, 0.5, 1.5, 0, -0.5, 0.5, 0.5, -0.5, 6, 11, 14, 9};
	float tile11[] = {11, 4, 1.5, 0, 0.5, 2.5, 0, 0.5, 2.5, 0, -0.5, 1.5, 0, -0.5, 3, 0, 17, 10};
	float tile12[] = {12, 3, -1.5, 0, -0.5, -0.5, 0.5, -0.5, -0.5, 0, -1.5, 8, 13, 15};
	float tile13[] = {13, 4, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0, -1.5, -0.5, 0, -1.5, 9, 14, 16, 12};
	float tile14[] = {14, 3, 0.5, 0.5, -0.5, 1.5, 0, -0.5, 0.5, 0, -1.5, 10, 17, 13};
	float tile15[] = {15, 5, -2.5, 0, -0.5, -1.5, 0, -0.5, -0.5, 0, -1.5, -0.5, 0, -2.5, -2.5, 0, -2.5, 7, 12, 16, 0, 0};
	float tile16[] = {16, 4, -0.5, 0, -1.5, 0.5, 0, -1.5, 0.5, 0, -2.5, -0.5, 0, -2.5, 13, 17, 0, 15};
	float tile17[] = {17, 5, 1.5, 0, -0.5, 2.5, 0, -0.5, 2.5, 0, -2.5, 0.5, 0, -2.5, 0.5, 0, -1.5, 11, 0, 0, 16, 14};
	float tee[] = {1, -2.25, 0, 2.0};
	float cup[] = {9, 0, 0.5, 0};
	
	drawTile(tile1);
	drawTile(tile2);
	drawTile(tile3);
	drawTile(tile4);
	drawTile(tile5);
	drawTile(tile6);
	drawTile(tile7);
	drawTile(tile8);
	drawTile(tile9);
	drawTile(tile10);
	drawTile(tile11);
	drawTile(tile12);
	drawTile(tile13);
	drawTile(tile14);
	drawTile(tile15);
	drawTile(tile16);
	drawTile(tile17);
	drawTee(tee);
	drawCup(cup);

}

void cb_display() {
	static clock_t previous_clock = 0;
	static clock_t ms_since_last = 0;
	clock_t now = clock() / (CLOCKS_PER_SEC / 1000);
	ms_since_last = now - previous_clock;
	if (ms_since_last < 20) {
		return;
	}
	previous_clock = now;
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glLoadIdentity();
	
	camera();
	
	draw_axis(4.0);

	//float tile[] = {1.0f, 4.0f, -.5f, 0.0f, 2.0f, .5f, 0.0f, 2.0f, .5f, 0.0f, -2.0f, -.5f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	//drawTile(tile);
	drawlevel2();
	
	glColor3f(1, 1, 1);
	
	glFlush();
	glutSwapBuffers(); // for smoother animation
}

void cb_idle() {
	glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("CMPS164 Lab 1: Minigolf Rendering");
	
	glutDisplayFunc(cb_display);
	glutReshapeFunc(cb_reshape);
	glutIdleFunc(cb_idle);
	glutKeyboardFunc(cb_keyboard);
	
	glClearColor(0,0,0,0); // set background to black
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	

	
	glutMainLoop();
	return 0;
}


