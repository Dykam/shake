#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <gccore.h>
#include <fat.h>
#include <wiiuse/wpad.h>

#include "menu.h"
#include "graphic.h"

Mtx GXmodelView2D;

		/*GRRLIB_DrawImg(40, 40, panel, 0, 1.0, 1.0, 0xFFFFFFFF);
		sprintf(txt_buffer, "This is a menu...");
		GRRLIB_Printf2(65, y, txt_buffer, 20, 0x00000000);
		y += 25;
		sprintf(txt_buffer, "Nothing yet...");
		GRRLIB_Printf2(65, y, txt_buffer, 20, 0x00000000);*/

/*
 * if(!!*(u32 *)0x80001800)
 */

int main(int argc, char **argv)
{
	WPAD_Init();
	WPAD_SetVRes(0, 640, 480);
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
		
	if (!fatInitDefault())	exit(0);
	
	srand(time(NULL)); 
	
	GRRLIB_Init();
	GRRLIB_InitFreetype();
	
	setup();
	
	while (1)
	{
		WPAD_ScanPads();
		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit(0);
		
		draw_screen();
		
		GRRLIB_Render();
	}
	
	return 0;
}
