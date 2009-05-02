#include <math.h>
#include <wiiuse/wpad.h>

#include "graphic.h"
#include "playground.h"

#define correct_ir_x(x) ((x / 640 * (640 + 48 * 2)) - 48)
#define correct_ir_y(y) ((y / 480 * (480 + 48 * 2)) - 48)

bool is_nunchuk_connected (WPADData *pad)
{
	 (pad->exp.type == WPAD_EXP_NUNCHUK) ? return true : return false;
}

void wiimote_handle_game (WPADData *pad)
{
	if (pad->btns_d & WPAD_BUTTON_HOME)
	{
		exit(0);
	}
	
	if (is_on_object(correct_ir_x(pad->ir.x), correct_ir_y(pad->ir.y), &objects))
	{
		if (pad->btns_d & WPAD_BUTTON_A)
		{
			switch (objects.action)
			{
				case 1: // Wiimote X axis
					while (1)
					{
						WPAD_ScanPads();
						pad = WPAD_Data(0);
						
						if (fabs(pad->gforce.x) > 2.5)
						{
							objects.x = random_number(1, 400);
							objects.y = random_number(1, 400);
							break;
						}
					}
					break;
				case 2: // Wiimote Y axis
					while (1)
					{
						WPAD_ScanPads();
						pad = WPAD_Data(0);
						
						if (fabs(pad->gforce.y) > 2.5)
						{
							objects.x = random_number(1, 400);
							objects.y = random_number(1, 400);
							break;
						}
					}	
					break;		
			}
		}
	}
}
