#include "Camera.h"

Camera::Camera() {



}

std::tuple<int, int> Camera::getPos(int x, int y, int w, int h, SDL_Rect player_rect, int display_width, int display_height) {

	std::tuple<int, int> newPos;

	if (player_rect.x < display_width / 2 - player_rect.w / 2 && player_rect.y < display_height / 2 - player_rect.h / 2) {
		newPos = std::make_tuple(x, y);
		return newPos;
	}

	if (player_rect.x < display_width / 2 - player_rect.w / 2) {
		newPos = std::make_tuple(x, y - player_rect.y + display_height / 2 - h / 2);
		return newPos;
	}

	if (player_rect.y < display_height / 2 - player_rect.h / 2) {

		newPos = std::make_tuple(x - player_rect.x + display_width / 2 - w / 2, y);
		return newPos;

	}

	//if (player_rect.x > )

	int newX = x - player_rect.x + display_width / 2 - w / 2;
	int newY = y - player_rect.y + display_height / 2 - h / 2;
	newPos = std::make_tuple(newX, newY);

	return newPos;

}