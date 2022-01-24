#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <tuple>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

class Player
{

public:

	Player(int display_width, int display_height);
	~Player();

	void draw(SDL_Renderer* renderer, std::tuple<int, int> cameraPos);

	void move(int direction);
	void update();

	SDL_Rect get_rect();
	std::tuple<int, int> get_pos();

private:

	TTF_Font* font;

	SDL_Texture* texture;
	SDL_Rect dstrect;
	std::tuple<int, int> pos;

	int x, y, w, h, vel = 2;

	bool right = false, left = false, up = false, down = false;

	int xp = 0, max_xp = 5, level = 1;

	struct Level_Info {
		std::string text;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Rect dstrect;
	};

	Level_Info level_info;

};

#endif