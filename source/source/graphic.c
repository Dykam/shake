#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "graphic.h"

#define __do_vector (x, y) (Vector v = {x, y, 0.0f})

void draw (GRRLIB_texImg tex, int x, int y, int rotation, int alpha)
{
	GRRLIB_DrawImg(x, y, tex, rotation, 1.0, 1.0, 0xFFFFFF00 | alpha);
}

void _printf (int x, int y, char *str, ...)
{
	char Buffer[1024];
	
	va_list args;
	va_start(args, str);
	vsprintf(Buffer, str, args);
	va_end(args);
	
	GRRLIB_initTexture();
	
	GRRLIB_Printf2(x, y, Buffer, 20, 0xFFFFFF);
	
	GRRLIB_DrawImg(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 0xFFFFFFFF);
}

