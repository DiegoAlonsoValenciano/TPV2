// This file is part of the course TPV2@UCM - Samir Genaim

#include "GameCtrlSystem.h"
#include "../ecs/Manager.h"
#include "../sdlutils/InputHandler.h"
#include "FruitSystem.h"
GameCtrlSystem::GameCtrlSystem()  {
	// TODO Auto-generated constructor stub

}

GameCtrlSystem::~GameCtrlSystem() {
	// TODO Auto-generated destructor stub
}

void GameCtrlSystem::initSystem() {
}

void GameCtrlSystem::update() {
	auto &ihldr = ih();

	if (ihldr.keyDownEvent()) {
		if (ihldr.isKeyDown(SDL_SCANCODE_SPACE)) {
		}
	}
}

void GameCtrlSystem::recieve(const Message &m) {
	switch (m.id) {
	case _m_STAR_EATEN:
		//score_ += mngr_->getComponent<Points>(m.star_eaten_data.e)->points_;
		break;
	default:
		break;
	}
}
