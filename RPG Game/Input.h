#pragma once

#ifndef INPUT_H
#define INPUT_H

#include <iostream>

#include <SDL/SDL.h>

#include "Engine.h"
#include "Player.h"

class Input
{

public:

	void update(Engine* engine, Player* player);

	bool initialize(void);

	bool is_key_triggered(const SDL_Scancode keys) const;
	bool is_key_pressed(const SDL_Scancode keys) const;
	bool is_key_released(const SDL_Scancode keys) const;

	bool is_button_triggered(const Uint32 button) const;
	bool is_button_pressed(const Uint32 button) const;
	bool is_button_released(const Uint32 button) const;

private:

	SDL_Event e;

	Uint8 prev_input[SDL_NUM_SCANCODES], curr_input[SDL_NUM_SCANCODES];
	Uint32 prev_mouse_state, curr_mouse_state;

	int prev_mouse_x, prev_mouse_y, curr_mouse_x, curr_mouse_y;


};

#endif