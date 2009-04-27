#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>

#include "graphic.h"
#include "playground.h"

#include "cursor_png.h"
#include "background_png.h"
#include "ball_png.h"

#define correct_ir_x(x) ((x / 640 * (640 + 48 * 2)) - 48)
#define correct_ir_y(y) ((y / 480 * (480 + 48 * 2)) - 48)

GRRLIB_texImg background;
GRRLIB_texImg hand;

movable *ball;

int current_screen = 1;
int points = 0;

void setup()
{
	ball = (movable *)malloc(sizeof(movable));
	ball->image = GRRLIB_LoadTexture(ball_png);
	ball->x = random_number(40, 80);
	ball->y = random_number(40, 120);
	ball->action = 1;
	background = GRRLIB_LoadTexture(background_png);
	hand = GRRLIB_LoadTexture(cursor_png);
}

bool is_on_object(int ir_x, int ir_y, movable *obj)
{
	return GRRLIB_PtInRect(obj->x - 30 , obj->y - 30, obj->image.w + 30, obj->image.h + 30, ir_x, ir_y);
}

void wiimote_handle_game ()
{
	WPAD_ScanPads();
	WPADData *pad = WPAD_Data(0);

	GRRLIB_initTexture();
	

	if (is_on_object(correct_ir_x(pad->ir.x), correct_ir_y(pad->ir.y), ball))
	{
		if (pad->btns_d & WPAD_BUTTON_A)
		{
			while (1)
			{
				WPAD_ScanPads();
				WPADData *pad = WPAD_Data(0);
				
				if (fabs(pad->gforce.x) > 1.5)
				{
					_printf(90, 100, "X : %1.3f Y : %1.3f", (float)pad->gforce.x, (float)pad->gforce.y);
							/*ball->x = random_number(10, 120);
							ball->y = random_number(10, 120);
							points++;*/
					break;
				}
			}
		}
	}
	
	GRRLIB_DrawImg(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 0xFFFFFFFF);
		
}

void wiimote_handler()
{
	WPADData * pad = WPAD_Data(0);
	
	if (pad->ir.valid)
	{
		GRRLIB_DrawImg(correct_ir_x(pad->ir.x), correct_ir_y(pad->ir.y), hand, pad->orient.roll, 1.0, 1.0, 0xFFFFFFFF);
	}
	
	switch(current_screen)
	{
		case 1:
			wiimote_handle_game();
	}
}

void draw_screen()
{
	GRRLIB_initTexture();
	
	switch(current_screen)
	{
		case 1:
			//GRRLIB_Rectangle(600, 100, 40, 60, 0x000000B2, 1);
			bounce(ball);	
			//_printf(20, 20, "You scored %05i points - battery : %i", points, (WPAD_BatteryLevel(0) * 100.0) / 4);
			GRRLIB_DrawImg(0, 0, background, 0, 1.0, 1.0, 0xFFFFFFFF);
			GRRLIB_DrawImg(ball->x, ball->y, ball->image, 0, 1.0, 1.0, 0xFFFFFFFF);
	}
	
	GRRLIB_DrawImg(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 0xFFFFFFFF);
	
	wiimote_handler();
}
