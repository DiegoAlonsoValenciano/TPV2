// This file is part of the course TPV2@UCM - Samir Genaim

#include "FruitSystem.h"

#include <algorithm>
#include"../components//ImageWithFrames.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "GameCtrlSystem.h"

FruitSystem::FruitSystem() : currNumOfFruits_(0) {
}

FruitSystem::~FruitSystem() {
}

void FruitSystem::initSystem() {
}

void FruitSystem::update() {

	auto currTime = sdlutils().currRealTime();
	auto stars = mngr_->getEntities(ecs::grp::FRUITS);
	auto n = stars.size();

	for (auto i = 0u; i < n; i++) {
		auto tr = mngr_->getComponent<Transform>(stars[i]);
	}
}

void FruitSystem::addFruit() {

	// Always use the random number generator provided by SDLUtils
	//
	auto &rand = sdlutils().rand();
	auto x = s;
	auto xAdd = (sdlutils().width()) / 8;
	auto y = s;
	auto yAdd = (sdlutils().height()) / 6;

	for (auto i = 0u; i <8; i++) {

		for (auto j = 0u; j < 6; j++)
		{
			// add and entity to the manager
			//
			auto e = mngr_->addEntity(ecs::grp::FRUITS);

			// add a Transform component, and initialise it with random
			// size and position
			//
			auto tr = mngr_->addComponent<Transform>(e);
			tr->init(Vector2D(x, y), Vector2D(), s, s, 0.0f);

			y += yAdd;
			// add an Image Component
			//
			mngr_->addComponent<ImageWithFrames>(e, &sdlutils().images().at("sprites"), 8, 8, 0, 0, 128, 128, 1, 4, 1, 1);

			currNumOfFruits_++;
		}
		y = s;
		x += xAdd;
	}
}

void FruitSystem::onStarEaten(ecs::entity_t e) {
	mngr_->setAlive(e, false);
	currNumOfFruits_--;
	// play sound on channel 1 (if there is something playing there
	// it will be cancelled
	sdlutils().soundEffects().at("pacman_eat").play(0, 1);
}

void FruitSystem::recieve(const Message &m) {
	switch (m.id) {
	case _m_FRUIT_EATEN:
		onStarEaten(m.fruit_eaten_data.e);
		break;
	case _m_CREATE_FRUITS:
		addFruit();
		break;
	default:
		break;
	}
}
