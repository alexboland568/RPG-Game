#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <tuple>

#include <SDL/SDL.h>

#include "TileMap.h"

class Camera
{

public:

	std::tuple<int, int> getPos(int x, int y, int w, int h, SDL_Rect player_rect, int display_width, int display_height);
};

#endif