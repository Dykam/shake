#include "grrlib/GRRLIB.h"

typedef struct 
{
	float x;
	float y;
	GRRLIB_texImg image;
	int action;
} movable;

movable objects;

void change_speed(int speed);
void bounce(movable *mov);
int random_number (int low, int max);
bool is_on_object(int ir_x, int ir_y, movable *obj);
movable create_object(int x, int y, int action, u8 * image);
void assign_action(movable *obj, WPADData *pad);
