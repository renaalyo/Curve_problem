#include "Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {
	if (radiusX <= 0 || radiusY <= 0) {
		throw std::invalid_argument("Radii should be positive");
	}
}

Point3D Ellipse::getPoint(double t) const {
	return { radiusX * cos(t), radiusY * sin(t), 0};
};

Point3D Ellipse::getDerivative(double t) const {
	//derivative of cos(x) = -sin(x)
	//derivative of sin(x) = cos(x)
	return { -radiusX * sin(t), radiusY * cos(t), 0};
};