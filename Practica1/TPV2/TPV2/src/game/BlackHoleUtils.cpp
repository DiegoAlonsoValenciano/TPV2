#include "BlackHoleUtils.h"
#include "../components/Image.h"
#include "../components/Transform.h"
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

		x = rand_.nextInt(20, sdlutils().width() - 20);
		y = rand_.nextInt(20, sdlutils().height() - 20);

		Vector2D p = Vector2D(x, y);
	}
}

void BlackHoleUtils::remove_BlackHole()
{
}

void BlackHoleUtils::generateBlackHole(const Vector2D& p)
{
	auto mngr = Game::instance()->getMngr();
	auto a = mngr->addEntity(ecs::grp::BLACKHOLE);
	int radius = rand_.nextInt(100, 300);
	int rot = rand_.nextInt(5, 10);
	mngr->addComponent<Transform>(a, p, Vector2D(0, 0), radius, radius, rot);
	mngr->addComponent<Image>(a, &sdlutils().images().at("black-hole"));
}
