/* Max Savage/Adam Wells Minigolf Rendering
  , atwells@ucsc.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "util.h"
#include <time.h>
#include <math.h>

void cb_keyboard(unsigned char key, int x, int y) {
	// Add controls to animation, joint movement control, etc.
	// Some camera functions are provided for model viewing convinience.
	switch(key) {
			
	}
}

void cb_reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
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
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lab 2: Robotic Animals");
	
	glutDisplayFunc(cb_display);
	glutReshapeFunc(cb_reshape);
	glutIdleFunc(cb_idle);
	glutKeyboardFunc(cb_keyboard);
	
	glClearColor(0,0,0,0); // set background to black
	glEnable(GL_DEPTH_TEST);
	
	glutMainLoop();
	
	
	
	return 0;
}

/*
void drawTile(float[] tile) {
	glBegin(GL_POLYGON);
	for(int i = 3; i < tile.length; i += 3) {
		glVertex3f(tile[i], tile[i+1], tile[i+2]);
	}
}
*/