#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <gccore.h>
#include <fat.h>
#include <wiiuse/wpad.h>

#include "menu.h"
#include "graphic.h"

Mtx GXmodelView2D;

void exit_game ()
{
	float alpha = 255;
	GRRLIB_texImg screen = GRRLIB_Screen2Texture();
	
	while (alpha > 0)
	{
		draw(screen, 0, 0, alpha);
 		GRRLIB_Render();
		alpha--;
	}
	
	GRRLIB_Exit();
	
	if(!!*(u32 *)0x80001800)
	{
		exit(0);
	}
	
	SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
}

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
		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit_game();
		
		draw_screen();
		
		GRRLIB_Render();
	}
	
	return 0;
}
