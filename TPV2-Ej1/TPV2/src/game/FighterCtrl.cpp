#include "FighterCtrl.h"
#include "../sdlutils/InputHandler.h"
#include "Container.h"

FighterCtrl::FighterCtrl()
	:left_(SDL_SCANCODE_LEFT), right_(SDL_SCANCODE_RIGHT), up_(SDL_SCANCODE_UP)
{
}

FighterCtrl::~FighterCtrl()
{
}

void FighterCtrl::handleInput(Container* o) {
	auto& ihdlr = ih();

	if (ihdlr.keyDownEvent()) {
		if (ihdlr.isKeyDown(left_)) {
			o->setRotation(o->getRotation()-5.0f);
		}
		else if (ihdlr.isKeyDown(right_)) {
			o->setRotation(o->getRotation() + 5.0f);
		}
		else if (ihdlr.isKeyDown(up_)) {
			auto& vel = o->getVel();
			vel = vel + Vector2D(0, -1).rotate(o->getRotation()) * 0.2;
			if (vel.magnitude() > 3.0f) {
				vel = vel.normalize() * 3.0f;
			}
		}
	}
}