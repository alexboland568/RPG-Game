#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

#include <SDL/SDL.h>

class Engine
{
public:

	Engine(std::string title, int width, int height);
	~Engine();

	SDL_Renderer* get_renderer();

	bool running = true; 

	int get_width();
	int get_height();

	void close();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	int width, height;

};

#endif