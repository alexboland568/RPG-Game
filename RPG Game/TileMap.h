#pragma once

#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class TileMap
{

public:

	TileMap(int display_width, int display_height);
	~TileMap();

private:

	struct Tile {



	};

	Tile tile[1][1];

	std::vector<SDL_Texture*> tile_textures;

	int rows, cols;

};

#endif