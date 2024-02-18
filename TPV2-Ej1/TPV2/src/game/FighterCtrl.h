#pragma once
#include "InputComponent.h"

#include <SDL.h>
class FighterCtrl: public InputComponent
{
public:
	FighterCtrl();
	virtual ~FighterCtrl();
	void handleInput(Container* o) override;

private:
	SDL_Scancode right_;
	SDL_Scancode left_;
	SDL_Scancode up_;
};