#include "Helix.h"

Helix::Helix(double radius, double step) : radius(radius), step(step) {
	if (radius <= 0) {
		throw std::invalid_argument("Radius should be positive");
	}
}

double Helix::getRadius() const {
	return radius;
}

Point3D Helix::getPoint(double t) const {
	return {radius * cos(t), radius * sin(t), step * t / (2* M_PI)};
}

Point3D Helix::getDerivative(double t) const {
	//derivative of cos(x) = -sin(x)
	//derivative of sin(x) = cos(x)
	return { -radius * sin(t), radius * cos(t), step * t / (2 * M_PI) };
}