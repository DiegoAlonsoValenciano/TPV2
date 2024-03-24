// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "../ecs/Manager.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../systems/CollisionsSystem.h"
#include "../systems/GameCtrlSystem.h"
#include "../systems/PacManSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/FruitSystem.h"
#include "../utils/Vector2D.h"
#include "../utils/Collisions.h"

#include "GameOverState.h"
#include "NewGameState.h"
#include "NewRoundState.h"
#include "PausedState.h"
#include "RunningState.h"

using ecs::Manager;

Game::Game() :
	mngr_(), //
	pacmanSys_(), //
	gameCtrlSys_(), //
	startsSys_(), //
	renderSys_(), //
	collisionSys_(),
	current_state_(nullptr), //
	paused_state_(nullptr), //
	runing_state_(nullptr), //
	newgame_state_(nullptr), //
	newround_state_(nullptr), //
	gameover_state_(nullptr) {

}

Game::~Game() {
	delete mngr_;
}

void Game::init() {

	// initialise the SDLUtils singleton
	SDLUtils::init("Demo", 800, 600, "resources/config/resources.json");

	// Create the manager
	mngr_ = new Manager();


	// add the systems
	pacmanSys_ = mngr_->addSystem<PacManSystem>();
	startsSys_ = mngr_->addSystem<FruitSystem>();
	gameCtrlSys_ = mngr_->addSystem<GameCtrlSystem>();
	renderSys_ = mngr_->addSystem<RenderSystem>();
	collisionSys_ = mngr_->addSystem<CollisionsSystem>();
	Message m;
	m.id = _m_CREATE_STARS;
	m.create_stars_data.n = 5;
	mngr_->send(m);
	newgame_state_ = new NewGameState();
	current_state_ = newgame_state_;
}

void Game::start() {

	// a boolean to exit the loop
	bool exit = false;

	auto& ihdlr = ih();

	while (!exit) {
		Uint32 startTime = sdlutils().currRealTime();

		// refresh the input handler
		ihdlr.refresh();

		if (ihdlr.isKeyDown(SDL_SCANCODE_ESCAPE)) {
			exit = true;
			continue;
		}

		current_state_->update();
		//pacmanSys_->update();
		//startsSys_->update();
		//gameCtrlSys_->update();
		//collisionSys_->update();

		//mngr_->refresh();

		//sdlutils().clearRenderer();
		//renderSys_->update();
		//sdlutils().presentRenderer();

		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}

}

