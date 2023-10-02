#pragma once
#include<string>
#include<vector>

struct Point
{
	int x;
	int y;
	int z;
};

class Shape
{
public:
	std::string getType()
	{
		return type;
	};

	virtual double getSquare();
	virtual double getVolume();
	virtual void print();
protected:
	std::string type;

};