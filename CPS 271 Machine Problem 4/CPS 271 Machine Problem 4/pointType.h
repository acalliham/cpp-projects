#pragma once

class pointType {

	double d_x;
	double d_y;

public:
	pointType();
	pointType(double x, double y);
	pointType(const pointType& point);
	void setCoord(double x, double y);
	void printCoord() const;
	double getX() const;
	double getY() const;
	void getData() const;
	void putData();
};