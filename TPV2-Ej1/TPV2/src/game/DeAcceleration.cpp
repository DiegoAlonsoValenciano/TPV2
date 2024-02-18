#include "DeAcceleration.h"

DeAcceleration::DeAcceleration() {

}

DeAcceleration::~DeAcceleration() {

}

void DeAcceleration::update(Container* o) {
	auto& vel = o->getVel();
	vel = vel * 0.995f;
}
