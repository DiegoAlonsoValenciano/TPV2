#include "GhostSystem.h"

#include <algorithm>
#include"../components//ImageWithFrames.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "GameCtrlSystem.h"

GhostSystem::GhostSystem() :currNumOfGost(0) {
}

GhostSystem::~GhostSystem() {

}

void GhostSystem::initSystem() {

}

void GhostSystem::update() {

}

void GhostSystem::addGhost() {
	if (currNumOfGost < 10) {
		auto& rand = sdlutils().rand();

		currNumOfGost++;
	}
}

void GhostSystem::onGhostEaten() {

	currNumOfGost--;
}

void GhostSystem::recieve(const Message& m) {

}

