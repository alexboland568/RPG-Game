#include "TileMap.h"

TileMap::TileMap(SDL_Renderer* renderer, int display_width, int display_height) {

	rows = display_height / 32;
	cols = display_width / 32;

	SDL_Surface* surface = IMG_Load("Res/grass.png");
	
	tiles = new Tile * [20];
	for (int i = 0; i < 20; i++)
		tiles[i] = new Tile [15];
	
	for (int i = 0; i < 20; i++) { 

		for (int j = 0; j < 15; j++) {

			Tile tile; 
			tile.texture = SDL_CreateTextureFromSurface(renderer, surface);
			tile.pos = std::make_tuple(i * 32, j * 32);
			tile.dstrect = {0, 0, 32, 32};
			tiles[i][j] = tile;

		}

	}


}

void TileMap::draw(SDL_Renderer* renderer, Camera* camera, int px, int py, int display_width, int display_height) {

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 15; j++) {

			std::tuple<int, int> camera_pos = camera->getPos(tiles[i][j].dstrect.x, tiles[i][j].dstrect.y, tiles[i][j].dstrect.w, tiles[i][j].dstrect.h, px, py, display_width, display_height);
			std::cout << std::get<0>(camera_pos) << std::endl; 
			tiles[i][j].dstrect = { std::get<0>(camera_pos), std::get<1>(camera_pos), 32, 32 };

			SDL_RenderCopy(renderer, tiles[i][j].texture, NULL, &tiles[i][j].dstrect);

		}

	}

}

TileMap::Tile** TileMap::get_tiles() {

	return tiles; 
	
}

TileMap::~TileMap() {

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 15; j++) {

			SDL_DestroyTexture(tiles[i][j].texture);

		}

	}
	for (int i = 0; i < 20; i++) {

		delete[] tiles[i];

	}

	delete tiles;



}