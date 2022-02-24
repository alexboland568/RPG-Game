#include "NPC.h"

NPC::NPC(SDL_Renderer* renderer, std::tuple<int, int> pos) {

	this->pos = pos; 

	dstrect = { std::get<0>(pos), std::get<1>(pos), 32, 32 };

	SDL_Surface* chat_surface = IMG_Load("Res/chat_icon.png");

	chat_icon.texture = SDL_CreateTextureFromSurface(renderer, chat_surface);
	SDL_FreeSurface(chat_surface);

}

void NPC::draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player, int display_width, int display_height) {

	std::tuple<int, int> camera_pos = camera->getPos(std::get<0>(pos), std::get<1>(pos), dstrect.w, dstrect.h, player, display_width, display_height);
	//pos = camera_pos;
	dstrect = { std::get<0>(camera_pos), std::get<1>(camera_pos), 32, 32 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	
	SDL_RenderFillRect(renderer, &dstrect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	if (in_range) {
		chat_icon.pos = camera_pos;
		chat_icon.dstrect = dstrect;
		SDL_RenderCopy(renderer, chat_icon.texture, NULL, &chat_icon.dstrect);
	}

}

std::tuple<int, int> NPC::get_pos() {

	return pos;

}

SDL_Rect NPC::get_rect() {

	return dstrect;

}