#include <iostream>
#include <iomanip>
#include "Point.h"

int main(){
    double x1, y1, x2, y2;

    std::cout << "Enter P1 coordinates separated by space" << std::endl;
    std::cin >> x1 >> y1;

    std::cout << "Point1 (" << std::fixed << std::setprecision(2) << x1 << "," << y1 << ")" << std::endl;

    std::cout << "Enter P2 coordinates separated by space" << std::endl;
    std::cin >> x2 >> y2;

    std::cout << "Point2 (" << std::fixed << std::setprecision(2) << x2 << "," << y2 << ")" << std::endl;

    Point p1 = {x1,y1};
    Point p2 = {x2,y2};

    double d = p1.distance(p2);

    std::cout << "The distance between these two points is: " << d << std::endl;

    return 0;
}