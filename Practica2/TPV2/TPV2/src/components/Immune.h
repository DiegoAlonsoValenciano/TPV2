#pragma once

#include "../ecs/Component.h"

class Immune: public ecs::Component
{
public:
	__CMPID_DECL__(ecs::cmp::IMMUNE)

	Immune();
	virtual ~Immune();
};

