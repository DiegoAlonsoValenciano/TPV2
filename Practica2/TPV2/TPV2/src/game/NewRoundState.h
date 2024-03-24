#include <SDL_rect.h>

#include "GameState.h"

class Texture;
class InputHandler;

class NewRoundState : public GameState {
public:
	NewRoundState();
	virtual ~NewRoundState();
	void enter() override;
	void leave() override;
	void update() override;

private:
	Texture& msg_;
	SDL_Rect dest_;
	InputHandler& ihdlr;
};