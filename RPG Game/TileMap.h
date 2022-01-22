#pragma once

#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include <tuple>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Camera.h"
class Camera;


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
		std::string type;

	};

	std::vector<Tile> get_tiles();

	bool get_collision(SDL_Rect rect);
	

private:


	
	
	std::vector<Tile> tiles;

	int rows = 0, cols = 0;
};

#endif