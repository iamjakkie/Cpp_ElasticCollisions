#include "Point.h"

double Point::distance(Point other){
    return sqrt(pow(_x-other.getX(),2)+pow(_y-other.getY(),2));
}