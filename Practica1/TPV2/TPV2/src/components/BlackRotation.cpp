#include "BlackRotation.h"

#include "../ecs/ecs.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "Transform.h"

BlackRotation::BlackRotation():tr_(nullptr), rand_(sdlutils().rand())
{

	rot_ = rand_.nextInt(5, 10);
}

BlackRotation::~BlackRotation()
{
}

void BlackRotation::initComponent()
{
	std::cout << "debug";
	tr_ = mngr_->getComponent<Transform>(ent_);
	assert(tr_ != nullptr);
}

void BlackRotation::update()
{
	std::cout << "debug";
	tr_->setRot(tr_->getRot() + rot_);
}
