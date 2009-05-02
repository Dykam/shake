#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>

#include "menu.h"
#include "input.h"

WPADData *pad;

int current_screen = 1;
int points = 0;

void* wiimote_handler()
{
		WPAD_ScanPads();
		pad = WPAD_Data(0);
		
		if (pad->ir.valid)
		{
			draw(cursor, pad->ir.x, pad->ir.y, pad->orient.roll, 255);
		}
		
		switch(current_screen)
		{
			case 1:
				wiimote_handle_game(pad);
		}
	
	return NULL;
}

// upper left, bottom left, bottom right, upper right
// Vector vc[] = {{10.0f,10.0f,0.0f}, {10.0f,200.0f,0.0f}, {200.0f,200.0f,0.0f}, {200.0f,10.0f,0.0f}};
Vector vc[] = {{0.0f,0.0f,0.0f}, {0.0f,480.0f,0.0f}, {200.0f,200.0f,0.0f}, {200.0f,10.0f,0.0f}};

void draw_screen()
{
	GRRLIB_FillScreen(0xFFFFFFFF);
	
	switch(current_screen)
	{
		case 1:
			GRRLIB_DrawImgQuad(vc, background, 0xFFFFFFFF);
			_printf(20, 20, "Shake 0.1 - TEST version");
			//GRRLIB_Rectangle(600, 100, 40, 60, 0x000000B2, 1);
			bounce(&objects);	
			wiimote_handler();
			//GRRLIB_DrawImg(0, 0, background, 0, 1.0, 1.0, 0xFFFFFFFF)
			GRRLIB_DrawImg(objects.x, objects.y, objects.image, 0, 1.0, 1.0, 0xFFFFFFFF);
	}
}

void setup()
{
	objects = create_object(20, 40, 2, (u8 *)ball_png);
	background = GRRLIB_LoadTexture(background_png);
	cursor = img2tex(cursor_png);
}
