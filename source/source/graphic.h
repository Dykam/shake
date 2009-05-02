/*
 *      graphic.h
 *      
 *      Copyright 2009 The Lemon Man <segnalazionidalweb@gmail.com>
 *      Copyright 2009 Dykam <dev@dykam.nl>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#include "grrlib/GRRLIB.h"

//------------------------------
// Images
//------------------------------

#include "cursor_png.h"
#include "background_png.h"
#include "ball_png.h"

GRRLIB_texImg background;
GRRLIB_texImg cursor;

#define img2tex(x) (GRRLIB_LoadTexture(x))

void draw (GRRLIB_texImg tex, int x, int y, int rotation, int alpha);
void _printf (int x, int y, char *str, ...);

