#include "grrlib/GRRLIB.h"

typedef struct
{
	float x;
	float y;
	GRRLIB_texImg image;
	int action;
} movable;

void draw_image (u8 * image, int x, int y, int alpha);
void _printf (int x, int y, char *str, ...);
