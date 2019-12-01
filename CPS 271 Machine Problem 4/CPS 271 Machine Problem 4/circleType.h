#pragma once
#include "pointType.h"

class circleType {

protected:
	double d_radius;
	pointType center;

public:
	circleType();
	circleType(double r, double x, double y);
	circleType(const pointType& p, double r = 1);
	circleType(const circleType& circle);
	void setRadius(double r);
	void printRadius() const;
	void setCenter(double x, double y);
	void printCenter() const;
	double calcArea() const;
	void printArea() const;
	double calcCircumference() const;
	void printCircumference() const;
	void getData() const;
	void putData();
};