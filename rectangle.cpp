#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, Point p3) 
{
	type = "Rectangle";
	Point p4 = fourthVertex(p1, p2, p3);
	points = { p1, p2, p3, p4 };
	sides = recSides(p1, p2, p3);
}

Point Rectangle::fourthVertex(Point p1, Point p2, Point p3) 
{
	Point p4{};
	if ((p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y) == 0) 
	{
		p4.x = p1.x + (p2.x - p1.x) + (p3.x - p1.x);
		p4.y = p1.y + (p2.y - p1.y) + (p3.y - p1.y);
		p4.z = p1.z + (p2.z - p1.z) + (p3.z - p1.z);
	}
	else if ((p1.x - p2.x) * (p3.x - p2.x) + (p1.y - p2.y) * (p3.y - p2.y) == 0) 
	{
		p4.x = p2.x + (p1.x - p2.x) + (p3.x - p2.x);
		p4.y = p2.y + (p1.y - p2.y) + (p3.y - p2.y);
		p4.z = p2.z + (p1.z - p2.z) + (p3.z - p2.z);
	}
	else if ((p1.x - p3.x) * (p2.x - p3.x) + (p1.y - p3.y) * (p2.y - p3.y) == 0) 
	{
		p4.x = p3.x + (p1.x - p3.x) + (p2.x - p3.x);
		p4.y = p3.y + (p1.y - p3.y) + (p2.y - p3.y);
		p4.z = p3.z + (p1.z - p3.z) + (p2.z - p3.z);
	}
	else {
		std::cout << "These points cannot be the vertices of a rectangle.\n";
	}
	return p4;
}

std::vector<double> Rectangle::recSides(Point p1, Point p2, Point p3) 
{
	double sideA{};
	double sideB{};
	double a = length(p1, p2);
	double b = length(p1, p3);
	double c = length(p2, p3);

	if (a > b && a > c) 
	{
		sideA = b;
		sideB = c;
	}
	else if (b > a && b > c) 
	{
		sideA = a;
		sideB = c;
	}
	else if (c > a && c > b) 
	{
		sideA = a;
		sideB = b;
	}
	return { sideA, sideB };
}

std::vector<double>& Rectangle::getSides() 
{
	return sides;
}

double Rectangle::getSquare() 
{
	return sides[0] * sides[1];
}

void Rectangle::print() {
	std::cout << getType() << " points: " << std::endl;

	for (auto& point : this->points)
	{
		std::cout << "{" << point.x << ", " << point.y << "} ";
	}

	std::cout << std::endl << "side a = " << sides[0] << " side b = " << sides[1];
	std::cout << std::endl << getType() << " square = " << this->getSquare() << std::endl;
}