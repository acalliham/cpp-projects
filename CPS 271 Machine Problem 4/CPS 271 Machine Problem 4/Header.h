#pragma once

class pointType {

	double d_x;
	double d_y;

public:
	pointType(double x = 0.0, double y = 0.0);
	void setCoord(double x, double y);
	void printCoord() const;
	double getX() const;
	double getY() const;

};