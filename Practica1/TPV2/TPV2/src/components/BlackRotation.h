#pragma once
#include "../ecs/Component.h"

class Transform;

class BlackRotation : public ecs::Component {
public:
	__CMPID_DECL__(ecs::cmp::BLACKROTATION)

		BlackRotation();
	virtual ~BlackRotation();
	void initComponent() override;
	void update() override;
private:
	Transform* tr_;
	int rot_;
};

