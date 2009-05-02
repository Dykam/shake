#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <gccore.h>
#include <fat.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <mp3player.h>

#include "bgm_mp3.h"

#include "menu.h"
#include "graphic.h"

Mtx GXmodelView2D;

void exit_game ()
{
	GRRLIB_texImg screen = GRRLIB_Screen2Texture();
	
	GRRLIB_DrawImg_FadeOut(screen, 1.0, 1.0, 1);
	
	MP3Player_Stop();
	GRRLIB_Exit();
	
	if(!!*(u32 *)0x80001800)
	{
		exit(0);
	}
	
	SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
}

int main(int argc, char **argv)
{
	// Initialize the wiimote
	
	WPAD_Init();
	WPAD_SetVRes(0, 640, 480);
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
		
	// Initialize fat access
	if (!fatInitDefault())	exit(0);
	
	// Initialize the random number generator
	srand(time(NULL)); 
	
	// Initialize GRRLIB
	GRRLIB_Init();
	GRRLIB_InitFreetype();
	GRRLIB_SetAntiAliasing(true);
	
	// Initialize the mp3 player
	ASND_Init();
	MP3Player_Init();

	MP3Player_PlayBuffer(bgm_mp3, bgm_mp3_size, NULL);
	
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
