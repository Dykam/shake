#include "grrlib/GRRLIB.h"

#define	BUTTON_STATE_NONE	0
#define BUTTON_STATE_HOVER	1

typedef struct
{
	float 			x;
	float			y;
	int				state;
	GRRLIB_texImg	button_image;
	GRRLIB_texImg	button_hover;
	char			button_text[200];
}	gui_button;
