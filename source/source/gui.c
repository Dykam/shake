#include <string.h>

#include "graphic.h"
#include "gui.h"

gui_button create_button (float x, float y, char *text, u8 * image, u8 * hover)
{
	static gui_button new_button;
	
	new_button.x = x;
	new_button.y = y;
	
	strncpy(new_button.button_text, text, 200);
	
	new_button.button_image = GRRLIB_LoadTexture(image);
	new_button.button_hover = GRRLIB_LoadTexture(hover);
	
	return new_button;
}

void draw_button (gui_button *button)
{
	draw(button->button_image, button->x, button->y, 0, 255);
	if (button->state == BUTTON_STATE_HOVER)
	{
		draw(button->button_hover ,button->x, button->y, 0, 255);
	}
	_printf(button->x + (button->button_image.w / 2) - (GRRLIB_TextWidth(button->button_text, 20) / 2) , \
			button->y + (button->button_image.h / 4) , \
			button->button_text);
}

bool is_on_button (float x, float y, gui_button *button)
{
	return GRRLIB_PtInRect(button->x, button->y, button->x + button->button_image.w, button->y + button->button_image.h, x, y);
}
		
	
