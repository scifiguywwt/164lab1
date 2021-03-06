/**
 * CMPS 160L (Fall 2011)
 * Lab 2: Animated Animal
 */

#ifndef UTIL_H
#define UTIL_H

enum cam_mode {DEFAULT, FRONT, SIDE, TOP, ANGLE, BACKUP, GOFORWARD, STOP, LEFT, RIGHT, UP, DOWN, ROTLEFT, ROTRIGHT, ROTUP, ROTDOWN};

void camera();

void set_cam(cam_mode newmode);

void draw_string( float x, float y, float z, char *txt );

void draw_axis(float len);

#endif