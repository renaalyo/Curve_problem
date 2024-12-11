#ifndef CIRCLE_H
#define CIRCLE_H

//#pragma once
#include "Curve.h"
class Circle : public Curve
{
public:
	Circle(double radius);

	double getRadius() const override;

	Point3D getPoint(double t) const override;
	Point3D getDerivative(double t) const override;

private:
	double radius;
};

#endif // !CIRCLE_H