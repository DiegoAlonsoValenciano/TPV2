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
	if (pos.getX() > sdlutils().width()) {
		pos = Vector2D(-o->getWidth(), pos.getY());
	}
	if (pos.getY() < -o->getHeight()) {
		pos = Vector2D(pos.getX(), sdlutils().height());
	}
	if (pos.getY() > sdlutils().height()) {
		pos = Vector2D(pos.getX(), -o->getHeight());
	}
}
