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
	void out_of_bounds(ecs::entity_t a) override;
private:
	RandomNumberGenerator& rand_;
	int width_;
	int height_;
};

