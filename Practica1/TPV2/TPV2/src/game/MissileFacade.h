// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/ecs.h"

class MissileFacade
{
public:
	MissileFacade(){}
	virtual ~MissileFacade(){}
	virtual void generate_missile() = 0;
	virtual void remove_all_missile() = 0;
};