#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "graphic.h"

void draw_image (u8 * image, int x, int y, int alpha)
{
	GRRLIB_texImg tex;
	
	tex = GRRLIB_LoadTexture(image);
	GRRLIB_DrawImg(x, y, tex, 0, 1.0, 1.0, alpha);
	
	free(&tex);
}

void _printf (int x, int y, char *str, ...)
{
	char Buffer[1024];
	
	va_list args;
	va_start(args, str);
	vsprintf(Buffer, str, args);
	va_end(args);
	
	GRRLIB_Printf2(x, y, Buffer, 20, 0xFFFFFF);
}
