#include <iostream>
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "parallelepiped.h"
#include "circle.h"
#include "cilinder.h"
#include "transform.hpp"


int main() 
{
    Point p1{ 1, 2, 3 };
    Point p2{ 6, 2, 3 };
    Point p3{ 1, 6, 3 };
    Point p4{ 1, 2, 5 };

    Line l{ p1, p2 };
    Transform<Line> trLine(l);
    l = trLine.scaleX(2);
    l.print();
    std::cout << std::endl;

    Rectangle r{ p1, p2, p3 };
    Transform<Rectangle> trRectangle(r);
    r = trRectangle.shift(1, 1, 1);
    r.print();
    std::cout << std::endl;

    Parallelepiped p{ p1, p2, p3, p4 };
    Transform<Parallelepiped> trPar(p);
    p = trPar.shift(1, 1, 1);
    p.print();
    std::cout << std::endl;

    Circle c(p1, 3);
    Transform<Circle> trCircle(c);
    c = trCircle.shift(1, 1, 1);
    c.print();
    std::cout << std::endl;

    Cilinder cyl(p1, 3, 5);
    Transform<Cilinder> trCylinder(cyl);
    cyl = trCylinder.scaleX(2);
    cyl.print();
    std::cout << std::endl;

}