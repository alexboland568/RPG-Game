#pragma once

#ifndef NPC_H
#define NPC_H

#include "Camera.h"
#include "Structures.h"

#include <string>
#include <tuple>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class NPC
{

public:

	NPC(SDL_Renderer* renderer, std::tuple<int, int> pos);

	void draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player, int display_width, int display_height);

	std::tuple<int, int> get_pos();
	SDL_Rect get_rect();

	Chat_Icon chat_icon; 

	bool in_range = false;


private:

	std::string name; 
	SDL_Texture* texture;
	SDL_Rect dstrect;
	int vel = 1;

	std::tuple<int, int> pos;

	
};

#endif