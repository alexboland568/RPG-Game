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

void Player::update(std::vector<Tile> tiles) {

	std::tuple<int, int> direction = std::make_tuple(0, 0);

	std::tuple<int, int> prev_pos = pos;

	if (right) {
		x += vel;
		direction = std::make_tuple(std::get<0>(direction) + 1, std::get<1>(direction));
	}
	if (left) {
		x -= vel;
		direction = std::make_tuple(std::get<0>(direction) - 1, std::get<1>(direction));
	}
	if (up) {
		y -= vel;
		direction = std::make_tuple(std::get<0>(direction), std::get<1>(direction) -1);
	}
	if (down) {
		y += vel;
		direction = std::make_tuple(std::get<0>(direction), std::get<1>(direction) + 1);
	}
	dstrect = { std::get<0>(prev_pos) + std::get<0>(direction) * vel, std::get<1>(prev_pos) + std::get<1>(direction) * vel, w, h };
	pos = std::make_tuple(std::get<0>(prev_pos) + std::get<0>(direction) * vel, std::get<1>(prev_pos) + std::get<1>(direction) * vel);

	if (get_collision(tiles)) {

		pos = prev_pos;
		dstrect = { std::get<0>(prev_pos), std::get<1>(prev_pos), w, h };

	}

}


bool Player::get_collision(std::vector<Tile> tiles) {

	for (int i = 0; i < tiles.size(); i++) {

		if (tiles[i].type == "Water") {

			if (std::get<0>(pos) < std::get<0>(tiles[i].pos) + tiles[i].dstrect.w && std::get<0>(pos) + dstrect.w > std::get<0>(tiles[i].pos) && std::get<1>(pos) < std::get<1>(tiles[i].pos) + tiles[i].dstrect.h && std::get<1>(pos) + dstrect.h > std::get<1>(tiles[i].pos)) {
				
				return true;

			}

		}

	}


	return false;

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