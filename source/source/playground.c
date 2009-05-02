#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <wiiuse/wpad.h>

#include "input.h"
#include "graphic.h"
#include "playground.h"

#define CANVAS_X 40
#define CANVAS_Y 80
#define CANVAS_WIDTH 600
#define CANVAS_HEIGHT 400
#define BALL_WIDTH 52
#define BALL_HEIGHT 52

float dx = 5.4, dy = 6.3; /* Change this to set different speeds. */

int random_number (int low, int max)
{
	return low + (int) ((double)max * (rand() / (RAND_MAX + (double)low)));
	//return (int) low + (rand() % max);
}

bool is_on_object(int ir_x, int ir_y, movable *obj)
{
	return GRRLIB_PtInRect(obj->x - 30 , obj->y - 30, obj->image.w + 30, obj->image.h + 30, ir_x, ir_y);
}

void assign_action(movable *obj, WPADData *pad)
{
	int action_max = 2;
	
	if (is_nunchuk_connected(pad)) action_max += 2;
	
	obj->action = random_number(1, action_max);
}

movable create_object(int x, int y, int action, u8 * image)
{
	static movable obj;
	
	obj.x = x;
	obj.y = y;
	obj.action = action;
	obj.image = img2tex(image);
	
	return obj;
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
			 
