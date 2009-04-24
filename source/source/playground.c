#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <wiiuse/wpad.h>

#include "graphic.h"

#define CANVAS_X 40
#define CANVAS_Y 80
#define CANVAS_WIDTH 600
#define CANVAS_HEIGHT 400
#define BALL_WIDTH 52
#define BALL_HEIGHT 52

float dx = 5.4, dy = 6.3; /* Change this to set different speeds. */

int random_number (int low, int max)
{
	//return low + (int) ((double)max * (rand() / (RAND_MAX + (double)low)));
	return (int) low + (rand() % max);
}

void assign_action(movable *mov)
{
	int new_action;
	new_action = random_number(1, 2);
	while (new_action == mov->action)
	{
		new_action = random_number(1, 2);
	}
	mov->action = new_action;
}	

void bounce(movable *mov)
{
	mov->x += dx;
	mov->y += dy;
	
	if (mov->x <= CANVAS_X)
	{
		mov->x = CANVAS_X;
		dx = -dx;
	}
	
	if (mov->x + BALL_WIDTH > CANVAS_WIDTH)
	{
		mov->x = CANVAS_WIDTH - BALL_WIDTH;
		dx = -dx;
	}
	
	if (mov->y < CANVAS_Y)
	{
		mov->y = CANVAS_Y;
		dy = -dy;
	}
	
	if (mov->y + BALL_HEIGHT >= CANVAS_HEIGHT)
	{
		mov->y = CANVAS_HEIGHT - BALL_HEIGHT;
		dy = -dy;
	}
}
			 
