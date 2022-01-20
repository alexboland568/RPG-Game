#pragma once

#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include <tuple>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Camera.h"

class TileMap
{


public:

	TileMap(SDL_Renderer* renderer, int display_width, int display_height);
	~TileMap();

	void draw(SDL_Renderer* renderer, Camera* camera, int px, int py, int display_width, int display_height);


	struct Tile {

		SDL_Texture* texture;
		std::tuple<int, int> pos;
		SDL_Rect dstrect;


	};

	Tile** get_tiles();

private:

	
	Tile** tiles = 0;

	int rows, cols;

};

#endif