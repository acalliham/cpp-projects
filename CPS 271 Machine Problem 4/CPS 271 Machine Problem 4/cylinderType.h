#pragma once
#include "circleType.h"
#include "pointType.h"

class cylinderType : public circleType {

protected:
	double d_height;

public:
	cylinderType();
	cylinderType(double h = 1, double r = 1, double x = 0, double y = 0);
	cylinderType(circleType c, double h = 1);
	cylinderType(const cylinderType& cylinder);
	double calcVolume() const;
	void printVolume() const;
	double calcSurfaceArea() const;
	void printSurfaceArea() const;
	void setHeight(double h);
	void printHeight() const;
	void getData() const;
	void putData();
};