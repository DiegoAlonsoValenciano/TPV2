#pragma once

#include "../ecs/Component.h"

class Miraculous : public ecs::Component
{
public:
	__CMPID_DECL__(ecs::cmp::MIRACULOUS)

	Miraculous();
	virtual ~Miraculous();
};

