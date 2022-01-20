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

	void draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player_rect, int display_width, int display_height);

	struct Tile {

		SDL_Texture* texture;
		std::tuple<int, int> pos;
		SDL_Rect dstrect;


	};

	Tile** tiles = 0;

	Tile** get_tiles();

private:

	
	
	int rows = 30, cols = 25;

};

#endif