#include "TileMap.h"



TileMap::TileMap(SDL_Renderer* renderer, int display_width, int display_height) {

	SDL_Surface* grass_surface = IMG_Load("Res/grass.png");
	SDL_Surface* water_surface = IMG_Load("Res/water.png");

	int grass_rows = 30, grass_cols = 25;
	int water_rows = 25, water_cols = 30;

	rows += grass_rows;
	rows += water_rows;
	cols += grass_cols;
	cols += water_cols;

	for (int i = 0; i < grass_rows; i++) {

		for (int j = 0; j < grass_cols; j++) {

			Tile tile; 
			tile.texture = SDL_CreateTextureFromSurface(renderer, grass_surface);
			tile.pos = std::make_tuple(i * 32, j * 32);
			tile.dstrect = {0, 0, 32, 32};
			tile.type = "Grass";
			tiles.push_back(tile);

		}

	}

	for (int i = 0; i < water_rows; i++) {

		for (int j = 0; j < water_cols; j++) {

			Tile tile;
			tile.texture = SDL_CreateTextureFromSurface(renderer, water_surface);
			//std::cout << std::get<1>(tiles[grass_rows * grass_cols - 1].pos) << std::endl; 
			tile.pos = std::make_tuple(i * 32, std::get<1>(tiles[(grass_rows * grass_cols) - 1].pos) + j * 32 + 32);
			tile.dstrect = { 0, 0, 32, 32 };
			tile.type = "Water";
			tiles.push_back(tile);

		}

	}
	
	SDL_FreeSurface(grass_surface);
	SDL_FreeSurface(water_surface);

}

void TileMap::draw(SDL_Renderer* renderer, Camera* camera, SDL_Rect player_rect, int display_width, int display_height) {

	get_collision(player_rect);

	for (int i = 0; i < tiles.size(); i++) {

		std::tuple<int, int> camera_pos = camera->getPos(std::get<0>(tiles[i].pos), std::get<1>(tiles[i].pos), tiles[i].dstrect.w, tiles[i].dstrect.h, player_rect, display_width, display_height);
		tiles[i].dstrect = { std::get<0>(camera_pos), std::get<1>(camera_pos), 32, 32 };

		SDL_RenderCopy(renderer, tiles[i].texture, NULL, &tiles[i].dstrect);

	}

}

bool TileMap::get_collision(SDL_Rect rect) {
	//std::cout << rect.y << std::endl; 
	//std::cout << tiles[0].dstrect.y << std::endl; 
	for (int i = 0; i < tiles.size(); i++) {

		if (tiles[i].type == "Water") {
			std::cout << tiles[i].dstrect.y << std::endl; 
			if (rect.x < tiles[i].dstrect.x + tiles[i].dstrect.w && rect.x + rect.w > tiles[i].dstrect.x && rect.y < tiles[i].dstrect.y + tiles[i].dstrect.h && rect.y + rect.h > tiles[i].dstrect.y) {
				
				return true;

			}

			else {

				return false;

			}

		}

	}

}

std::vector<TileMap::Tile> TileMap::get_tiles() {

	return tiles; 
	
}

TileMap::~TileMap() {

	for (int i = 0; i < tiles.size(); i++)
		SDL_DestroyTexture(tiles[i].texture);

}