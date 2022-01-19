#include "Camera.h"

std::tuple<int, int> Camera::getPos(int x, int y, int w, int h, int px, int py, int display_width, int display_height) {

	int newX = x - px + display_width / 2 - w / 2;
	int newY = y - py + display_height / 2 - h / 2;

	std::tuple<int, int> newPos = std::make_tuple(newX, newY);

	return newPos;

}