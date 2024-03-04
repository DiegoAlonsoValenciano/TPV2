#include "BlackHoleUtils.h"
#include "../components/Image.h"
#include "../components/Transform.h"
#include "../components/BlackRotation.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "Game.h"

BlackHoleUtils::BlackHoleUtils():rand_(sdlutils().rand()), width_(sdlutils().width()), height_(sdlutils().height())
{
};
void BlackHoleUtils::create_BlackHole()
{
	for (int i = 0; i < 6; i++) {
		int y = 0, x = 0;
		int radius = rand_.nextInt(50, 150);
		x = rand_.nextInt(radius, sdlutils().width() - radius);
		y = rand_.nextInt(radius, sdlutils().height() - radius);
	
		Vector2D p = Vector2D(x, y);
		generateBlackHole(p, radius);
	}

}

void BlackHoleUtils::remove_BlackHole()
{
	auto mngr = Game::instance()->getMngr();
	for (auto e : mngr->getEntities(ecs::grp::BLACKHOLE)) {
		mngr->setAlive(e, false);
	}
	mngr->refresh();
}

void BlackHoleUtils::generateBlackHole(const Vector2D& p, int radius)
{
	auto mngr = Game::instance()->getMngr();
	auto a = mngr->addEntity(ecs::grp::BLACKHOLE);
	int rot = rand_.nextInt(5, 10);
	mngr->addComponent<Transform>(a, p, Vector2D(0, 0), radius, radius, rot);
	mngr->addComponent<BlackRotation>(a);
	mngr->addComponent<Image>(a, &sdlutils().images().at("black-hole"));
}
