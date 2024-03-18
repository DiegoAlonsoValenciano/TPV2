// This file is part of the course TPV2@UCM - Samir Genaim

#include "RenderSystem.h"

#include "../components/Image.h"
#include "../components/ImageWithFrames.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/macros.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/Texture.h"
#include "GameCtrlSystem.h"

RenderSystem::RenderSystem() {

}

RenderSystem::~RenderSystem() {
}

void RenderSystem::initSystem() {
}

void RenderSystem::update() {
	drawMsgs();
	drawStars();
	drawPacMan();
}

void RenderSystem::drawStars() {
	// draw stars
	for (auto e : mngr_->getEntities(ecs::grp::STARS)) {

		auto tr = mngr_->getComponent<Transform>(e);
		auto tex = mngr_->getComponent<Image>(e)->tex_;
		draw(tr, tex);
	}
}

void RenderSystem::drawPacMan() {
	auto e = mngr_->getHandler(ecs::hdlr::PACMAN);
	auto tr = mngr_->getComponent<Transform>(e);
	auto iwf = mngr_->getComponent<ImageWithFrames>(e);
	//draw(tr, tex);
	drawFrame(tr, iwf);
}


void RenderSystem::drawMsgs() {
	// draw the score
	//
	auto score = mngr_->getSystem<GameCtrlSystem>()->getScore();

	Texture scoreTex(sdlutils().renderer(), std::to_string(score),
			sdlutils().fonts().at("ARIAL24"), build_sdlcolor(0x444444ff));

	SDL_Rect dest = build_sdlrect( //
			(sdlutils().width() - scoreTex.width()) / 2.0f, //
			10.0f, //
			scoreTex.width(), //
			scoreTex.height());

	scoreTex.render(dest);

	// draw add stars message
	sdlutils().msgs().at("addstars").render(10, 10);

}

void RenderSystem::draw(Transform *tr, Texture *tex) {
	SDL_Rect dest = build_sdlrect(tr->pos_, tr->width_, tr->height_);

	assert(tex != nullptr);
	tex->render(dest, tr->rot_);
}

void RenderSystem::drawFrame(Transform* tr, ImageWithFrames* iwf) {
	auto tex_ =iwf-> 
	if (sdlutils().virtualTimer().currTime() > lastFrameChange_ + 50) {
		lastFrameChange_ = sdlutils().virtualTimer().currTime();
		currFrameC_ = (currFrameC_ + 1) % ncol_;
		if (currFrameC_ == 0)
			currFrameR_ = (currFrameR_ + 1) % nrow_;
	}

	int r = (currFrameR_ + srow_);
	int c = (currFrameC_ + scol_);
	auto src = build_sdlrect(c * frameWidth_ + x_, r * frameHeight_ + y_, w_,
		h_);

	auto dest = build_sdlrect(tr_->getPos(), tr_->getWidth(), tr_->getHeight());

	tex_->render(src, dest, tr_->getRot());
}
