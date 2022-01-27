#include "NPC.h"

NPC::NPC(std::tuple<int, int> pos) {

	this->pos = pos; 

	dstrect = { std::get<0>(pos), std::get<1>(pos), 32, 32 };

}

void NPC::draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player, int display_width, int display_height) {

	std::tuple<int, int> camera_pos = camera->getPos(std::get<0>(pos), std::get<1>(pos), dstrect.w, dstrect.h, player, display_width, display_height);
	dstrect = { std::get<0>(camera_pos), std::get<1>(camera_pos), 32, 32 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	
	SDL_RenderFillRect(renderer, &dstrect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}

std::tuple<int, int> NPC::get_pos() {

	return pos;

}

SDL_Rect NPC::get_rect() {

	return dstrect;

}