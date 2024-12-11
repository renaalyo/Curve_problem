#ifndef HELIX_H
#define HELIX_H

//#pragma once
#include "Curve.h"
class Helix : public Curve
{
public:
	Helix(double radius, double step);

	Point3D getPoint(double t) const override;
	Point3D getDerivative(double t) const override;

private:
	double radius, step;
};
#endif // !HELIX_H