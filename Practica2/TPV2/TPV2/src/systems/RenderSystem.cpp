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
	drawStars();
	drawPacMan();
}

void RenderSystem::drawStars() {
	// draw stars
	for (auto e : mngr_->getEntities(ecs::grp::FRUITS)) {

		auto tr = mngr_->getComponent<Transform>(e);
		auto tex = mngr_->getComponent<ImageWithFrames>(e)->tex_;
		auto iwf = mngr_->getComponent<ImageWithFrames>(e);
		drawFrame(tr,iwf);
	}
}

void RenderSystem::drawPacMan() {
	auto e = mngr_->getHandler(ecs::hdlr::PACMAN);
	auto tr = mngr_->getComponent<Transform>(e);
	auto iwf = mngr_->getComponent<ImageWithFrames>(e);
	//draw(tr, tex);
	drawFrame(tr, iwf);
}


void RenderSystem::draw(Transform *tr, Texture *tex) {
	SDL_Rect dest = build_sdlrect(tr->pos_, tr->width_, tr->height_);

	assert(tex != nullptr);
	tex->render(dest, tr->rot_);
}

void RenderSystem::drawFrame(Transform* tr, ImageWithFrames* iwf) {

	auto ncol = iwf->ncol_;
	auto nrow = iwf->nrow_;
	auto scol = iwf->scol_;
	auto srow = iwf->srow_;
	auto frameWidth = iwf->frameWidth_;
	auto frameHeight = iwf->frameHeight_;
	auto x = iwf->x_;
	auto y = iwf->y_;
	auto w = iwf->w_;
	auto h = iwf->h_;
	if (sdlutils().virtualTimer().currTime()> iwf->lastFrameChange_ + 50) {
		iwf->lastFrameChange_ = sdlutils().virtualTimer().currTime();
		iwf->currFrameC_ = (iwf->currFrameC_ + 1) % ncol;
		if (iwf->currFrameC_ == 0)
			iwf->currFrameR_ = (iwf->currFrameR_ + 1) % nrow;
	}
		int r = (iwf->currFrameR_ + srow);
		int c = (iwf->currFrameC_ + scol);
		auto src = build_sdlrect(c * frameWidth + x, r * frameHeight + y, w,
			h);
	
	auto dest = build_sdlrect(tr->getPos(), tr->getWidth(), tr->getHeight());

	iwf->tex_->render(src, dest, tr->getRot());
}
