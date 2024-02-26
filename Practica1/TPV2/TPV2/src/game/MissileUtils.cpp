#include "MissileUtils.h"

#include "../components/Follow.h"
#include "../components/Image.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "Game.h"

MissileUtils::MissileUtils()
	:rand_(sdlutils().rand())
{}

MissileUtils::~MissileUtils() {

}

void MissileUtils::remove_all_missile() {
	auto mngr = Game::instance()->getMngr();
	for (auto e : mngr->getEntities(ecs::grp::MISSILE)) {
		mngr->setAlive(e, false);
	}
	mngr->refresh();
}

void MissileUtils::generate_missile() {

}
