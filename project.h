#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include "sense.h"
#include <linux/input.h>

//display grid and framebuffer.
void openFrameBuffer();

void closeFrameBuffer(void);

void display_grid(int);

void clearDisplay();


//gyroscope and data euler angles. 
void open_gyro();

void close_gyro();

void check_gyro();

void configure_gyro();

//access and check joytick inputs.
void openJoystick();

void closeJoystick();

void checkJoystick();


//get and set functions in input.c
float get_phi();

int get_step();

int * int2binary(int);

void display_diff(void);



int angle_adj(int);

float get_p0();
float get_p();
int get_ang_disp();


