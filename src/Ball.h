#ifndef BALL_H
#define BALL_H

#include <mutex>
#include <deque>
#include <condition_variable>

#include "CylinderObject.h"
#include "Constants.h"

class Wall;

template <typename T>
class MessageQueue{
    public:
     T receive();
     void send(T&& msg);
     int getSize();

    private:
     std::mutex _mutex;
     std::condition_variable _cond;
     std::deque<T> _queue;
};

enum class CollisionType {
    wallCollision,
    bottomCollision,
    pistonCollision,
};

struct CollisionData {
    CollisionType type;
    double velY;
};

class Ball : public CylinderObject, public std::enable_shared_from_this<Ball> {
    public:
     Ball();
     void setWalls(std::vector<std::shared_ptr<Wall>> walls) { _walls = walls;}
     void setBalls(std::vector<std::shared_ptr<Ball>> balls) { _balls = balls;}
     
     void setRadius(double r) { _radius = r;}
     double getRadius() { return _radius;}

     void setSpecificDirection(double speed, double angle);

     void setRandomDirection(double speed);

     void setGravity(double ball_gravity) { _ball_gravity = ball_gravity; }
     void setGasMode(bool gas_mode) { _gas_mode = gas_mode; }

     bool dataIsAvailable();
     CollisionData receiveMsg();
     void simulate();
     void setShutdown();

     std::shared_ptr<Ball> get_shared_this(){ return shared_from_this(); }

    private:
     void play();
     bool checkWallCollision(double nextX, double nextY, std::shared_ptr<Wall> wall);
     bool checkBallCollision(double nextX, double nextY, std::shared_ptr<Ball> ball);

     bool getShutdown();

     double _radius;
     double _ball_gravity;
     bool _gas_mode;
     std::vector<std::shared_ptr<Wall>> _walls;
     std::vector<std::shared_ptr<Ball> _balls;

     MessageQueue<CollisionData> _msgQueue;
     std::mutex _mutex;

     bool _shutDown;
};

#endif