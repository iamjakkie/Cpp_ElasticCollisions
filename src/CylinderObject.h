#ifndef CylinderObject_H
#define CylinderObject_H

#include <vector>
#include <thread>
#include <mutex>

enum class ObjectType{
    noObject,
    objectBall,
    objectWall,
};

class CylinderObject{
    public:
     CylinderObject();
     ~CylinderObject();

     int getID() { return _id; };
     void setPosition(double x, double y);
     void getPosition(double& x, double& y);

     void setVelocity(double velX, double velY);
     void getVelocity(double& velX, double& velY);

     double getSpeed();

     void setMass(double m);
     double getMass();

     ObjectType getType() { return _type; }

     virtual void simulate() {};

    protected:
     ObjectType _type;
     int _id;
     double _posX, _posY;
     double _velX, _velY, _speed; 
     double _mass;

     std::vector<std::thread> _threads;
     std::mutex _mutex;
     static std::mutex _mtxCout;

    private:
     static int _idCnt;
}