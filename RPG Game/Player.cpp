#include "Player.h"

Player::Player(int display_width, int display_height) {

	font = TTF_OpenFont("Res/OpenSans-Regular.ttf", 25);

	x = display_width / 2;
	y = display_height / 2;
	w = 32;
	h = 32; 

	pos = std::make_tuple(x, y);

	dstrect = { x, y, w, h };

	Level_Info level_info;
	

}

void Player::draw(SDL_Renderer* renderer, std::tuple<int, int> cameraPos) {

	dstrect = { std::get<0>(cameraPos), std::get<1>(cameraPos), w, h};

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &dstrect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_Color font_color = { 255, 255, 255 };
	level_info.text = "Level: " + std::to_string(level);
	level_info.surface = TTF_RenderText_Solid(font, level_info.text.c_str(), font_color);
	level_info.texture = SDL_CreateTextureFromSurface(renderer, level_info.surface);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(level_info.texture, NULL, NULL, &texW, &texH);
	level_info.dstrect = { 0, 0, texW, texH };
	SDL_RenderCopy(renderer, level_info.texture, NULL, &level_info.dstrect);
}

void Player::move(int direction) {

	if (direction == 1) {

		right = true;

	}

	if (direction == -1) {

		right = false;

	}

	if (direction == 2) {

		left = true;

	}

	if (direction == -2) {

		left = false;

	}

	if (direction == 3) {

		up = true;

	}

	if (direction == -3) {

		up = false;

	}

	if (direction == 4) {

		down = true; 

	}

	if (direction == -4) {

		down = false;

	}

}

void Player::update() {

	if (right)
		x += vel;
	if (left)
		x -= vel;
	if (up)
		y -= vel;
	if (down)
		y += vel;
	dstrect = { x, y, w, h };
	pos = std::make_tuple(x, y);

}

SDL_Rect Player::get_rect() {

	return dstrect;

}

std::tuple<int, int> Player::get_pos() {

	return pos; 

}

void Player::set_pos(std::tuple<int, int> pos) {

	this->pos = pos;

}

Player::~Player() {

	SDL_FreeSurface(level_info.surface);
	SDL_DestroyTexture(level_info.texture);

	TTF_CloseFont(font);

}