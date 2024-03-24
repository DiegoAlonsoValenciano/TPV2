// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/System.h"

class FruitSystem: public ecs::System {
public:

	__SYSID_DECL__(ecs::sys::STARS)

	FruitSystem();
	virtual ~FruitSystem();
	void initSystem() override;
	void update() override;
	void addFruit();
	void onStarEaten(ecs::entity_t e);
	void recieve(const Message &m) override;
private:
	bool milagroso = false;
	unsigned int currNumOfFruits_;
	int s = 25;
};

