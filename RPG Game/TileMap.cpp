#include "TileMap.h"

TileMap::TileMap(int display_width, int display_height) {

	rows = display_height / 32;
	cols = display_width / 32;

}

TileMap::~TileMap() {



}