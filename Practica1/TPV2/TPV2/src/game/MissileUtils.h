#pragma once

#include "MissileFacade.h"

class Vector2D;
class RandomNumberGenerator;

class MissileUtils: public MissileFacade
{
public:
	MissileUtils();
	virtual ~MissileUtils();
	void generate_missile() override;
	void remove_all_missile() override;
private:
	RandomNumberGenerator& rand_;
};

