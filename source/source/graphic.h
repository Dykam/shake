#include "grrlib/GRRLIB.h"

typedef struct
{
	float x;
	float y;
	GRRLIB_texImg image;
	int action;
} movable;

#define img2tex(x) (GRRLIB_LoadTexture(x))

void draw (GRRLIB_texImg tex, int x, int y, float alpha);
void _printf (int x, int y, char *str, ...);
