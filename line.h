#pragma once
#include "shape.h"
#include <vector>

class Line :public Shape
{
public:
	Line() {};
	Line(Point p1, Point p2);
	std::vector<Point>& getPoints();

	double length(Point p1, Point p2);
	void print() override;

protected:
	std::vector<Point> points{};
};