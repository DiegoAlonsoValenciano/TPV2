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
	Vector2D SpawnPoint(int radius);

private:
	void generateBlackHole(const Vector2D& p,int radius);
	RandomNumberGenerator& rand_;
	int width_;
	int height_;

};