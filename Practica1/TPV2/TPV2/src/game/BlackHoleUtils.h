#pragma once
#include "BlackHoleFacade.h"

class Vector2D;
class RandomNumberGenerator;

class BlackHoleUtils : public BlackHoleFacade
{
public: 
	BlackHoleUtils();
	virtual ~BlackHoleUtils() {};
	void create_BlackHole() override;
	void remove_BlackHole() override;

private:
	void generateBlackHole(const Vector2D& p, const Vector2D& v, int g);
	RandomNumberGenerator& rand_;
	int width_;
	int height_;
	int rot_;
	int radius_;
};