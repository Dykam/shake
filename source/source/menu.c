#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>

#include "menu.h"
#include "input.h"

WPADData 	*pad;
lwp_t		wpad_handler_thread;

int current_screen = 0;
int points = 0;

static void * wiimote_handler()
{
	while (1)
	{
			WPAD_ScanPads();
			pad = WPAD_Data(0);
			
			if (pad->ir.valid)
			{
				draw(cursor, pad->ir.x, pad->ir.y, pad->orient.roll, 255);
			}
			
			switch(current_screen)
			{
				case 0:
					break;
				case 1:
					wiimote_handle_game(pad);
					break;
			}
	}
}

void main_menu()
{
	GRRLIB_DrawImg(0, 0, background, 0, 1.0, 1.0, 0xFFFFFFFF);
	_printf(30, (640 / 2) - GRRLIB_TextWidth("Shake!", 20), "Shake!");
	
	if (is_pressed(pad, WPAD_BUTTON_A))
		current_screen = 1;
}

// upper left, bottom left, bottom right, upper right
// Vector vc[] = {{10.0f,10.0f,0.0f}, {10.0f,200.0f,0.0f}, {200.0f,200.0f,0.0f}, {200.0f,10.0f,0.0f}};
Vector vc[] = {{0.0f,0.0f,0.0f}, {0.0f,480.0f,0.0f}, {200.0f,200.0f,0.0f}, {200.0f,180.0f,0.0f}};

void draw_screen()
{
	GRRLIB_FillScreen(0xFFFFFFFF);
	
	switch(current_screen)
	{
		case 0:
			main_menu();
			break;
		case 1:
			GRRLIB_DrawImgQuad(vc, background, 0xFFFFFFFF);
			_printf(20, 20, "Shake 0.1 - TEST version");
			bounce(&objects);	
			draw(objects.image, objects.x, objects.y, 0, 255);
			break;
	}
	
	//wiimote_handler();
}

void setup()
{
	volatile int arg = 0;
	LWP_CreateThread(&wpad_handler_thread, wiimote_handler, (void *)&arg, NULL, 0, 50);
	
	objects = create_object(random_number(40, 400), random_number(40, 400), 2, (u8 *)ball_png);
	background = img2tex(background_png);
	cursor = img2tex(cursor_png);
}
