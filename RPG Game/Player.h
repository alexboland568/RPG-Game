#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <tuple>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "Structures.h"

#include "TileMap.h"
#include "NPC.h"

class Player
{

public:

	Player(int display_width, int display_height);
	~Player();

	void draw(SDL_Renderer* renderer, std::tuple<int, int> cameraPos);

	void move(int direction);
	void update(std::vector<Tile> tiles, std::vector<NPC> npcs);

	bool get_collision(std::vector<Tile> tiles), get_collision(std::vector<NPC> npcs);

	SDL_Rect get_rect();
	std::tuple<int, int> get_pos();
	void set_pos(std::tuple<int, int> pos);

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