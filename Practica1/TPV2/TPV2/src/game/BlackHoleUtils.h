#pragma once
#include "BlackHoleFacade.h"

class Vector2D;
class RandomNumberGenerator;

class BlackHoleUtils : public BlackHoleFacade
{
public: 
	BlackHoleUtils() {};
	virtual ~BlackHoleUtils() {};
	void create_BlackHole() override;
	void remove_BlackHole() override;

private:
};