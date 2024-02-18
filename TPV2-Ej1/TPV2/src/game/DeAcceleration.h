#pragma once
#include "PhysicsComponent.h"
#include "Container.h"
class DeAcceleration: public PhysicsComponent
{
public:
	DeAcceleration();
	virtual ~DeAcceleration();
	void update(Container* o) override;
};

