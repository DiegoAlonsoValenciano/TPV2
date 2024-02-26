#include "BlackHoleUtils.h"
#include "../components/Image.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "Game.h"

BlackHoleUtils::BlackHoleUtils():rand_(sdlutils().rand()), width_(sdlutils().width()), height_(sdlutils().height())
{
	rot_ = rand_.nextInt(5, 10);
	radius_ = rand_.nextInt(100, 300);
};
void BlackHoleUtils::create_BlackHole()
{
	for (int i = 0; i < 6; i++) {
		int y = 0, x = 0;
	}
}

void BlackHoleUtils::remove_BlackHole()
{
}
