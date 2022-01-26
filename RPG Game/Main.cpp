#include <iostream>
#include <tuple>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "Engine.h"
#include "Camera.h"
#include "Input.h"
#include "TileMap.h"
#include "Player.h"
#include "NPC.h"

int main(int argc, char** argv) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		return EXIT_FAILURE;

	}
	
	if (IMG_Init(IMG_INIT_PNG) < 0)
		return EXIT_FAILURE;

	if (TTF_Init() < 0)
		return EXIT_FAILURE;

	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frame_start;
	int frame_time;

	Engine* engine = new Engine("RPG", 640, 480);

	Camera* camera = new Camera();

	Input* input = new Input();
	input->initialize();

	TileMap* tilemap = new TileMap(engine->get_renderer(), engine->get_width(), engine->get_height());

	Player* player = new Player(engine->get_width(), engine->get_height());
	NPC* npc = new NPC(std::make_tuple(40, 40));
	while (engine->running) {

		frame_start = SDL_GetTicks();

		input->update(engine, player);
		SDL_RenderClear(engine->get_renderer());
		
		
		// Draw 

		tilemap->draw(engine->get_renderer(), camera, player , engine->get_width(), engine->get_height());

		player->draw(engine->get_renderer(), camera->getPos(player->get_rect().x, player->get_rect().y, player->get_rect().w, player->get_rect().h, player->get_rect(), engine->get_width(), engine->get_height()));
		
		player->update(tilemap->get_tiles());
		//std::cout << "(" << player->get_rect().x << ", " << player->get_rect().y << ")" << std::endl; 
		npc->draw(engine->get_renderer(), camera, player->get_rect(), engine->get_width(), engine->get_height());

		SDL_RenderPresent(engine->get_renderer());

	
		frame_time = SDL_GetTicks() - frame_start;

		if (FRAME_DELAY > frame_time)
			SDL_Delay(FRAME_DELAY - frame_time);

	}

	delete engine;
	delete player;
	delete camera;
	delete input;
	delete tilemap;

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();

	return 0;

}