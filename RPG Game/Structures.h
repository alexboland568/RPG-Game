#include <string>
#include <tuple>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Tile {

	SDL_Texture* texture;
	std::tuple<int, int> pos;
	SDL_Rect dstrect;
	std::string type;

};

#endif