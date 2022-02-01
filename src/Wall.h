#ifndef WALL_H
#define WALL_H

#include "CylinderObject.h"

enum class WallType{
    lateral,
    piston,
    bottom,
};

class Wall: public CylinderObject, public std::enable_shared_from_this<Wall>{
    public:
     Wall();

     void setSize(double w, double h);
     void getSize(double& w, double& h);
     void setHeat(double ht);
     double getHeat();
     void setWallType(WallType type) { _wallType = type; }
     WallType getWallType() { return _wallType; }

     std::shared_ptr<Wall> get_shared_this() { return shared_from_this(); }

    private:
     double _width, _height;
     double _temp;
     WallType _wallType;
};

#endif