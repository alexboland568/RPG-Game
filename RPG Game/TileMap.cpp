#include "TileMap.h"

extern 

TileMap::TileMap(SDL_Renderer* renderer, int display_width, int display_height) {

	SDL_Surface* surface = IMG_Load("Res/grass.png");
	
	tiles = new Tile * [rows];
	for (int i = 0; i < rows; i++)
		tiles[i] = new Tile [cols];
	
	for (int i = 0; i < rows; i++) { 

		for (int j = 0; j < cols; j++) {

			Tile tile; 
			tile.texture = SDL_CreateTextureFromSurface(renderer, surface);
			tile.pos = std::make_tuple(i * 32, j * 32);
			tile.dstrect = {0, 0, 32, 32};
			tiles[i][j] = tile;

		}

	}


}

void TileMap::draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player_rect, int display_width, int display_height) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::tuple<int, int> camera_pos = camera->getPos(std::get<0>(tiles[i][j].pos), std::get<1>(tiles[i][j].pos), tiles[i][j].dstrect.w, tiles[i][j].dstrect.h, player_rect, display_width, display_height);
			tiles[i][j].dstrect = { std::get<0>(camera_pos), std::get<1>(camera_pos), 32, 32 }; 
			
			SDL_RenderCopy(renderer, tiles[i][j].texture, NULL, &tiles[i][j].dstrect);

		}

	}

}

TileMap::Tile** TileMap::get_tiles() {

	return tiles; 
	
}

TileMap::~TileMap() {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			SDL_DestroyTexture(tiles[i][j].texture);

		}

	}
	for (int i = 0; i < rows; i++) {

		delete[] tiles[i];

	}

	delete tiles;



}