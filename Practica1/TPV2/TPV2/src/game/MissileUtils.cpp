#include "MissileUtils.h"

#include "../components/Follow.h"
#include "../components/Image.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "Game.h"

MissileUtils::MissileUtils()
	:rand_(sdlutils().rand()), width_(sdlutils().width()), height_(
		sdlutils().height())
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
	int corner = rand_.nextInt(0, 4);
	int x = 0;
    int y = 0;

	switch (corner)
	{
	case 0:
		x = 0;
		y = 0;
		break;
	case 1:
		x = width_;
		y = 0;
		break;
	case 2:
		x = width_;
		y = height_;
		break;
	case 3:
		x = 0;
		y = height_;
		break;
	default:
		break;
	}

	Vector2D p = Vector2D(x, y);

	auto mngr = Game::instance()->getMngr();

	auto m = mngr->addEntity(ecs::grp::MISSILE);
	auto fighter = mngr->getHandler(ecs::hdlr::FIGHTER);
	auto fighterTR = mngr->getComponent<Transform>(fighter);

	Vector2D d = fighterTR->getPos();

	Vector2D v = (d - p).normalize() * (rand_.nextInt(1, 4));

	mngr->addComponent<Transform>(m,p,v, 15, 15, Vector2D(0, -1).angle(v));

	mngr->addComponent<Follow>(m, fighterTR->getPos());

	mngr->addComponent<Image>(m, &sdlutils().images().at("missle"));

}
