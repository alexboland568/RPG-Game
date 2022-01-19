#include "Engine.h"

Engine::Engine(std::string title, int width, int height) {

	this->width = width;
	this->height = height;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (window == NULL)
		std::cout << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL)
		std::cout << SDL_GetError() << std::endl; 

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}

SDL_Renderer* Engine::get_renderer() {

	return renderer;

}

int Engine::get_width() {

	return width;

}

int Engine::get_height() {

	return height;

}

void Engine::close() {

	running = false; 

}
Engine::~Engine() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

}