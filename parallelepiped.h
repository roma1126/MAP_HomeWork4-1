#pragma once
#include "rectangle.h"

class Parallelepiped : public Rectangle 
{
public:
	Parallelepiped() {};
	Parallelepiped(Point p1, Point p2, Point p3, Point h);

	double getSquare() override;
	double getVolume() override;
	void print() override;
};