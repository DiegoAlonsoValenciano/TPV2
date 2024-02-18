#include "ShowAtOpposieSide.h"

ShowAtOpposieSide::ShowAtOpposieSide() {

}

ShowAtOpposieSide::~ShowAtOpposieSide() {

}

void ShowAtOpposieSide::update(Container* o) {
	auto& pos = o->getPos();
	if (pos.getX()< -o->getWidth()) {
		pos = Vector2D(sdlutils().width()-5, pos.getY());
	}
}
