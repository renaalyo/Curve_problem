#ifndef CURVE_H
#define CURVE_H

#pragma once
#define _USE_MATH_DEFINES //for M_PI

#include "Point3D.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

class Curve
{
public:
	virtual ~Curve() = default;

	virtual double getRadius() const { return 0; }
	
	virtual Point3D getPoint(double t) const = 0;
	virtual Point3D getDerivative(double t) const = 0;
};

#endif // !CURVE_H