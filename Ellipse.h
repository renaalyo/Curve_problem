#ifndef ELLIPSE_H
#define ELLIPSE_H

#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	Ellipse(double radiusX, double radiusY);

	Point3D getPoint(double t) const override;
	Point3D getDerivative(double t) const override;

private:
	double radiusX, radiusY;
};

#endif // !ELLIPSE_H