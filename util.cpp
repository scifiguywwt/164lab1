#include "util.h"

#include <GLUT/glut.h>

cam_mode cmode = DEFAULT;
float xTrans = 0.0, yTrans = -1.0, zTrans = -8.0;
float xRot = 0.0, yRot = 0.0, zRot = 0.0;

// Some camera functions are provided for viewing convinience
void camera() {
	// back up to be able to see our objects
	glTranslatef(xTrans, yTrans, zTrans);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	
	switch(cmode) {
		case DEFAULT:
			break;
		case FRONT:
			//glRotatef( 90, 0.0, 1.0, 0.0 );
			yRot = 90;
			xRot = 0;
			zRot = 0;
			xTrans = 0;
			yTrans = 0;
			zTrans = -8.0;
			break;
		case SIDE:
			glRotatef( 180, 0.0, 1.0, 0.0 );
			break;
		case TOP:
			glRotatef( -90, 1.0, 0.0, 0.0 );
			break;
		case ANGLE:
			glRotatef( 45, 0.0, 1.0, 0.0 );
			break;
			
		case STOP:
			break;

		case BACKUP:
			zTrans-=.05;
			break;
		case GOFORWARD:
			zTrans+=.05;
			break;
			
		case LEFT:
			xTrans+=.05;
			break;
		case RIGHT:
			xTrans-=.05;
			break;
			
		case UP:
			yTrans+=.05;
			break;
		case DOWN:
			yTrans-=.05;
			break;
			
		case ROTLEFT:
			yRot += 1;
			break;
		case ROTRIGHT:
			yRot -= 1;
			break;
		case ROTUP:
			xRot += 1;
			break;
		case ROTDOWN:
			xRot -= 1;
			break;








		case 'q':
			//exit(0);
			break;

	}
}

// Sets camera to specified mode
void set_cam(cam_mode newmode) {
	cmode = newmode;
}

// Draw string at specified coords x, y, z
void draw_string( float x, float y, float z, char *txt ) {
	glRasterPos3f(x, y, z);
	while(*txt != '\0') {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *txt);
		txt++;
	}
}

// Draw axis, w/specified length
void draw_axis(float len) {
	// Axis colors
	float c[4][3] = {
		{len, 0, 0},
		{0, len, 0},
		{0, 0, len},
		{len, len, len}};
	
	// Direction labels
	char* txt[3] = {"+X", "+Y", "+Z"};
	
	// Vertex positions  
	float v[4][3] = {
		{len, 0, 0},
		{0, len, 0},
		{0, 0, len},
		{0, 0, 0}};
	
	glPushMatrix();
	
	// Draw axis
	for( int i = 0; i < 3; i++ ) {		
		glBegin( GL_LINES );
		glColor3fv(c[i]);
		glVertex3fv(v[i]);
		glColor3fv(c[3]);
		glVertex3fv(v[3]);
		glEnd();
	}
	
	glColor3f(1, 1, 1);
	
	draw_string(v[0][0], v[0][1], v[0][2], txt[0]);
	draw_string(v[1][0], v[1][1], v[1][2], txt[1]);
	draw_string(v[2][0], v[2][1], v[2][2], txt[2]);
	
	glPopMatrix();
}