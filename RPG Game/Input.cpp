#include "Input.h"

bool Input::initialize(void) {

	memset(prev_input, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
	memcpy(curr_input, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);

	prev_mouse_x = 0;
	prev_mouse_y = 0;
	prev_mouse_state = 0;
	curr_mouse_state = SDL_GetMouseState(&curr_mouse_x, &curr_mouse_y);

	return true;

}

void Input::update(Engine* engine, Player* player) {

	SDL_PollEvent(&e);

	if (e.type == SDL_QUIT)
		engine->close();

	memcpy(prev_input, curr_input, sizeof(Uint8) * SDL_NUM_SCANCODES);
	memcpy(curr_input, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);

	prev_mouse_x = curr_mouse_x;
	prev_mouse_y = curr_mouse_y;
	prev_mouse_state = curr_mouse_state;

	curr_mouse_state = SDL_GetMouseState(&curr_mouse_x, &curr_mouse_y);

	if (is_key_triggered(SDL_SCANCODE_D))
		player->move(1);
	if (is_key_released(SDL_SCANCODE_D))
		player->move(-1);
	if (is_key_triggered(SDL_SCANCODE_A))
		player->move(2);
	if (is_key_released(SDL_SCANCODE_A))
		player->move(-2);
	if (is_key_triggered(SDL_SCANCODE_W))
		player->move(3);
	if (is_key_released(SDL_SCANCODE_W))
		player->move(-3);
	if (is_key_triggered(SDL_SCANCODE_S))
		player->move(4);
	if (is_key_released(SDL_SCANCODE_S))
		player->move(-4);

}

bool Input::is_key_triggered(const SDL_Scancode keys) const {

	return (curr_input[keys] == 1 && prev_input[keys] == 0);

}

bool Input::is_key_pressed(const SDL_Scancode keys) const {

	return (curr_input[keys] == 1);

}

bool Input::is_key_released(const SDL_Scancode keys) const {

	return (curr_input[keys] == 0 && prev_input[keys] == 1);

}

bool Input::is_button_triggered(const Uint32 uButton) const
{
	return ((SDL_BUTTON(uButton) & curr_mouse_state) != 0) && ((SDL_BUTTON(uButton) & prev_mouse_state) == 0);
}

bool Input::is_button_pressed(const Uint32 uButton) const
{
	return (SDL_BUTTON(uButton) & curr_mouse_state) != 0;
}

bool Input::is_button_released(const Uint32 uButton) const
{
	return ((SDL_BUTTON(uButton) & curr_mouse_state) == 0) && ((SDL_BUTTON(uButton) & prev_mouse_state) != 0);
}