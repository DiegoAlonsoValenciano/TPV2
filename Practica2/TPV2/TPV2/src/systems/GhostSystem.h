#pragma once

#include "../ecs/System.h"

struct Transform;

class GhostSystem:public ecs::System
{
public:
	__SYSID_DECL__(ecs::sys::GHOST)

	GhostSystem();
	virtual ~GhostSystem();
	void initSystem() override;
	void update() override;
	void addGhost();
	void onGhostEaten();
	void recieve(const Message& m) override;
private:
	int currNumOfGost;
};

