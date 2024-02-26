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

void MissileUtils::generate_missile() {

}

void MissileUtils::remove_all_missile() {

}
