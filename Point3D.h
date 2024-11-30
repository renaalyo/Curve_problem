#ifndef POINT3D_H
#define POINT3D_H
#pragma once


struct Point3D {
	double x, y, z;
	Point3D() : x(0), y(0), z(0) {};
	Point3D(double val) : x(val), y(val), z(val) {};
	Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};
};

#endif // POINT3D_H