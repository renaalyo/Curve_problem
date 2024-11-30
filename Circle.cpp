#include "Circle.h"

Circle::Circle(double radius) : radius(radius) {
	if (radius <= 0) {
		throw std::invalid_argument("Radius should be positive");
	}
}

double Circle::getRadius() const {
	return radius;
}

Point3D Circle::getPoint(double t) const{
	return {radius * cos(t), radius * sin(t), 0};
};

Point3D Circle::getDerivative(double t) const {
	//derivative of cos(x) = -sin(x)
	//derivative of sin(x) = cos(x)
	return { -radius * sin(t), radius * cos(t), 0};
};