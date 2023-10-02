#pragma once
#include "circle.h"

class Cilinder : public Circle 
{
public:
	Cilinder() {};
	Cilinder(Point centre, double height, double radius);

	double getSquare() override;

	double getVolume() override;

	void print() override;

protected:
	double height_{};
};