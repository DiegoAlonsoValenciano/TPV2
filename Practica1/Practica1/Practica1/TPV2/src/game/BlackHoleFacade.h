#pragma once
#include "../ecs/ecs.h"

using ecs::entity_t;
class BlackHoleFacade
{
public:
	BlackHoleFacade() {};
	virtual ~BlackHoleFacade() {};
	virtual void create_BlackHole() = 0;
	virtual void remove_BlackHole() = 0;
};