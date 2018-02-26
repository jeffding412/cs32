#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

///////////////////////////////////////////////////
///////////////////// Actor ///////////////////////
///////////////////////////////////////////////////
class Actor : public GraphObject
{
public:
    Actor(int imageID, double startX, double startY, int dir, double size, int depth, StudentWorld* world);
    StudentWorld* getWorld() const;
    bool isAlive() const;
    void setDead();
    virtual void doSomething() = 0;
    virtual void move() = 0;
    int getImageID() const;
private:
    bool m_Status;
    StudentWorld* m_world;
    int m_id;
};

///////////////////////////////////////////////////
////////////////////// Star ///////////////////////
///////////////////////////////////////////////////
class Star : public Actor
{
public:
    Star(double startX, double startY, StudentWorld* world);
    virtual void doSomething();
    virtual void move();
private:
};

///////////////////////////////////////////////////
////////////////////// Ship ///////////////////////
///////////////////////////////////////////////////
class Ship : public Actor
{
public:
    Ship(int imageID, double startX, double startY, int dir, double size, int depth, StudentWorld* world, int startHealth);
    virtual void doSomething() = 0;
    virtual void move() = 0;
    virtual void sufferDamage(int collidedID) = 0;
    void decreaseHealth(int amount);
    void increaseHealth(int amount);
    int getHealth();
private:
    int m_Health;
};

///////////////////////////////////////////////////
///////////// NachenBlaster ///////////////////////
///////////////////////////////////////////////////
class NachenBlaster : public Ship
{
public:
    NachenBlaster(StudentWorld* world);
    virtual void doSomething();
    virtual void move();
    virtual void sufferDamage(int collidedID);
    int getTorpedoes();
    void addTorpedoes();
    int getCabbage();
    void goodiePickedUp(int collidedID);
private:
    int m_CabbagePoints;
    int m_torpedoes;
    int m_keyValue;
};

///////////////////////////////////////////////////
//////////////// Projectile ///////////////////////
///////////////////////////////////////////////////
class Projectile : public Actor
{
public:
    Projectile(int imageID, double startX, double startY, int dir, StudentWorld* world);
    virtual void doSomething();
    virtual void move() = 0;
    bool isOffScreen();
private:
};

///////////////////////////////////////////////////
/////////////////// Cabbage ///////////////////////
///////////////////////////////////////////////////
class Cabbage : public Projectile
{
public:
    Cabbage(double startX, double startY, StudentWorld* world);
    virtual void move();
private:
};

///////////////////////////////////////////////////
/////////////////// Torpedo ///////////////////////
///////////////////////////////////////////////////
class Torpedo : public Projectile
{
public:
    Torpedo(double startX, double startY, int dir, StudentWorld* world);
    virtual void move();
private:
};

///////////////////////////////////////////////////
//////////////////// Turnip ///////////////////////
///////////////////////////////////////////////////
class Turnip : public Projectile
{
public:
    Turnip(double startX, double startY, StudentWorld* world);
    virtual void move();
private:
};

///////////////////////////////////////////////////
///////////////////// Alien ///////////////////////
///////////////////////////////////////////////////
class Alien : public Ship
{
public:
    Alien(int imageID, double startX, double startY, StudentWorld* world, int startHealth);
    virtual void doSomething();
    virtual void move();
    virtual void sufferDamage(int collidedID);
    virtual void deathSequence() = 0;
    double getTravelSpeed();
    void setTravelSpeed(double speed);
    int getFlightPlanLength();
    void setFlightPlanLength(int length);
    int getDirection();
    void setDirection(int direction);
    bool needNewFlightPlan();
    bool withinRangeNB();
    virtual bool withinRangeAction() = 0;
private:
    double m_travel_speed;
    int m_flight_plan_length;
    int m_direction; //0 is going straight, 1 is going up, 2 is going down
};

///////////////////////////////////////////////////
////////////////// Smallgon ///////////////////////
///////////////////////////////////////////////////
class Smallgon : public Alien
{
public:
    Smallgon(double startX, double startY, StudentWorld* world);
    virtual bool withinRangeAction();
    virtual void deathSequence();
private:
};

///////////////////////////////////////////////////
////////////////// Smoregon ///////////////////////
///////////////////////////////////////////////////
class Smoregon : public Alien
{
public:
    Smoregon(double startX, double startY, StudentWorld* world);
    virtual bool withinRangeAction();
    virtual void deathSequence();
private:
};

///////////////////////////////////////////////////
////////////////// Snagglegon /////////////////////
///////////////////////////////////////////////////
class Snagglegon : public Alien
{
public:
    Snagglegon(double startX, double startY, StudentWorld* world);
    virtual bool withinRangeAction();
    virtual void deathSequence();
private:
};

///////////////////////////////////////////////////
//////////////////// Goodie ///////////////////////
///////////////////////////////////////////////////
class Goodie : public Actor
{
public:
    Goodie(int imageID, double startX, double startY, StudentWorld* world);
    virtual void doSomething();
    virtual void move();
private:
};

///////////////////////////////////////////////////
//////////////// Extra Life Goodie ////////////////
///////////////////////////////////////////////////
class ExtraLifeGoodie : public Goodie
{
public:
    ExtraLifeGoodie(double startX, double startY, StudentWorld* world);
private:
};

///////////////////////////////////////////////////
////////////////// Repair Goodie //////////////////
///////////////////////////////////////////////////
class RepairGoodie : public Goodie
{
public:
    RepairGoodie(double startX, double startY, StudentWorld* world);
private:
};

///////////////////////////////////////////////////
//////////////// Torpedo Goodie ///////////////////
///////////////////////////////////////////////////
class TorpedoGoodie : public Goodie
{
public:
    TorpedoGoodie(double startX, double startY, StudentWorld* world);
private:
};

///////////////////////////////////////////////////
////////////////// Explosion //////////////////////
///////////////////////////////////////////////////
class Explosion : public Actor
{
public:
    Explosion(double startX, double startY, StudentWorld* world);
    virtual void doSomething();
    virtual void move();
private:
    int m_frameNumber;
};


#endif // ACTOR_H_
