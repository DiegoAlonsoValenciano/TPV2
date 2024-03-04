// This file is part of the course TPV2@UCM - Samir Genaim

#include "RunningState.h"

#include "../components/Gun.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../utils/Collisions.h"
#include "AsteroidsFacade.h"
#include "FighterFacade.h"
#include"BlackHoleFacade.h"
#include "MissileFacade.h"

#include "Game.h"

RunningState::RunningState(AsteroidsFacade* ast_mngr,
	FighterFacade* fighter_mngr, BlackHoleFacade* black_mngr, MissileFacade* missile_mngr_):
	ihdlr(ih()), //
	ast_mngr_(ast_mngr), //
	fighter_mngr_(fighter_mngr), //
	black_mngr_(black_mngr),
	missile_mngr_(missile_mngr_),
	lastTimeGeneratedAsteroids_(),
    lastTimeGeneratedMissile_(){
}

RunningState::~RunningState() {
}

void RunningState::leave() {
}

void RunningState::update() {

	auto mngr = Game::instance()->getMngr();

	// check if fighter won
	if (mngr->getEntities(ecs::grp::ASTEROIDS).size() == 0) {
		Game::instance()->setState(Game::GAMEOVER);
		return;
	}

	// move to pause if P pressed
	if (ihdlr.keyDownEvent() && ihdlr.isKeyDown(SDL_SCANCODE_P)) {
		Game::instance()->setState(Game::PAUSED);
		return;
	}

	auto fighter = mngr->getHandler(ecs::hdlr::FIGHTER);
	auto& asteroids = mngr->getEntities(ecs::grp::ASTEROIDS);
	auto& blackHole = mngr->getEntities(ecs::grp::BLACKHOLE);
	auto& missile = mngr->getEntities(ecs::grp::MISSILE);

	// update
	mngr->update(fighter);
	for (auto a : asteroids) {
		mngr->update(a);
	}
	for (auto a : missile) {
		mngr->update(a);
	}
	for (auto a : blackHole)
	{
		mngr->update(a);
	}

	// check collisions
	checkCollisions();

	// render
	sdlutils().clearRenderer();
	for (auto a : asteroids) {
		mngr->render(a);
	}
	mngr->render(fighter);
	for (auto b : blackHole)
	{
		mngr->render(b);
	}
	for (auto a : missile) {
		mngr->render(a);
	}
	sdlutils().presentRenderer();

	mngr->refresh();

	if (sdlutils().virtualTimer().currTime() > lastTimeGeneratedAsteroids_ + 5000) {
		ast_mngr_->create_asteroids(1);
		lastTimeGeneratedAsteroids_ = sdlutils().virtualTimer().currTime();
	}
	if (sdlutils().virtualTimer().currTime() > lastTimeGeneratedMissile_ + 15000) {
		missile_mngr_->generate_missile();
		lastTimeGeneratedMissile_ = sdlutils().virtualTimer().currTime();
	}

}

void RunningState::enter() {
	lastTimeGeneratedAsteroids_ = sdlutils().virtualTimer().currTime();
	lastTimeGeneratedMissile_ = sdlutils().virtualTimer().currTime();
}

void RunningState::checkCollisions() {
	auto mngr = Game::instance()->getMngr();
	auto fighter = mngr->getHandler(ecs::hdlr::FIGHTER);
	auto& asteroids = mngr->getEntities(ecs::grp::ASTEROIDS);
	auto& black = mngr->getEntities(ecs::grp::BLACKHOLE);
	auto& missiles = mngr->getEntities(ecs::grp::MISSILE);
	auto fighterTR = mngr->getComponent<Transform>(fighter);
	auto fighterGUN = mngr->getComponent<Gun>(fighter);

	auto num_of_asteroids = asteroids.size();
	for (auto i = 0u; i < num_of_asteroids; i++) {
		auto a = asteroids[i];
		if (!mngr->isAlive(a))
			continue;

		// asteroid with fighter
		auto aTR = mngr->getComponent<Transform>(a);
		if (Collisions::collidesWithRotation( //
			fighterTR->getPos(), //
			fighterTR->getWidth(), //
			fighterTR->getHeight(), //
			fighterTR->getRot(), //
			aTR->getPos(), //
			aTR->getWidth(), //
			aTR->getHeight(), //
			aTR->getRot())) {
			onFigherDeath();
			return;
		}
		// asteroid with bullets
		for (Gun::Bullet& b : *fighterGUN) {
			if (b.used) {
				if (Collisions::collidesWithRotation( //
					b.pos, //
					b.width, //
					b.height, //
					b.rot, //
					aTR->getPos(), //
					aTR->getWidth(), //
					aTR->getHeight(), //
					aTR->getRot())) {
					ast_mngr_->split_astroid(a);
					b.used = false;
					sdlutils().soundEffects().at("explosion").play();
					continue;
				}
			}
		}

		for (auto b : black)
		{
			auto blckTR = mngr->getComponent<Transform>(b);
			if (Collisions::collidesWithRotation( //
				blckTR->getPos(), //
				blckTR->getWidth(), //
				blckTR->getHeight(), //
				blckTR->getRot(), //
				aTR->getPos(), //
				aTR->getWidth(), //
				aTR->getHeight(), //
				aTR->getRot())) 
			{
				auto& pos = aTR->getPos();
				pos.setX(sdlutils().rand().nextInt(aTR->getWidth(), sdlutils().width() - aTR->getWidth()));
				pos.setY(sdlutils().rand().nextInt(aTR->getWidth(), sdlutils().height() - aTR->getHeight()));
		     }
		}

	}

	auto num_of_missiles = missiles.size();
	for (auto i = 0u; i < num_of_missiles; i++) {
		auto a = missiles[i];
		if (!mngr->isAlive(a))
			continue;

		// asteroid with fighter
		auto aTR = mngr->getComponent<Transform>(a);
		if (Collisions::collidesWithRotation( //
			fighterTR->getPos(), //
			fighterTR->getWidth(), //
			fighterTR->getHeight(), //
			fighterTR->getRot(), //
			aTR->getPos(), //
			aTR->getWidth(), //
			aTR->getHeight(), //
			aTR->getRot())) {
			onFigherDeath();
			return;
		}
		if (aTR->getPos().getX()+ aTR->getWidth() < 0.0f || aTR->getPos().getY()+aTR->getHeight() < 0.0f || aTR->getPos().getX() > sdlutils().width() || aTR->getPos().getY() > sdlutils().height()) {
			mngr->setAlive(a, false);
			return;
		}
		// asteroid with bullets
		for (Gun::Bullet& b : *fighterGUN) {
			if (b.used) {
				if (Collisions::collidesWithRotation( //
					b.pos, //
					b.width, //
					b.height, //
					b.rot, //
					aTR->getPos(), //
					aTR->getWidth(), //
					aTR->getHeight(), //
					aTR->getRot())) {
					mngr->setAlive(a, false);
					b.used = false;
					sdlutils().soundEffects().at("explosion").play();
					continue;
				}
			}
		}

	}

	auto num_of_blackholes = black.size();

	for (auto i = 0u; i< num_of_blackholes;i++)
	{
		auto a = black[i];

		auto blckTR = mngr->getComponent<Transform>(a);
		if (Collisions::collidesWithRotation( //
			fighterTR->getPos(), //
			fighterTR->getWidth(), //
			fighterTR->getHeight(), //
			fighterTR->getRot(), //
			blckTR->getPos(), //
			blckTR->getWidth(), //
			blckTR->getHeight(), //
			blckTR->getRot())) {
			onFigherDeath();
			return;
		}
	}



}

void RunningState::onFigherDeath() {
	sdlutils().soundEffects().at("explosion").play();
	if (fighter_mngr_->update_lives(-1) > 0)
		Game::instance()->setState(Game::NEWROUND);
	else
		Game::instance()->setState(Game::GAMEOVER);
}
