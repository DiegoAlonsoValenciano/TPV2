#pragma once
#include "PhysicsComponent.h"
#include "../sdlutils/SDLUtils.h"
#include "Container.h"
class ShowAtOpposieSide: public PhysicsComponent
{
public:
	ShowAtOpposieSide();
	virtual ~ShowAtOpposieSide();
	void update(Container* o) override;
private:

};

