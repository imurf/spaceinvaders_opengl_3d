#ifndef _PHYSICS_TYPES_HPP_
#define _PHYSICS_TYPES_HPP_

#include <math.h>
#include <iostream>
#include "../config.hpp"

class Position2D
{
public:
  Position2D() : x(0.f), y(0.f){}
  Position2D(float x, float y) : x(x), y(y){}

  void operator+=(Position2D p){this->x+=p.x; this->y+=p.y;}
  void operator-=(Position2D p){this->x-=p.x; this->y-=p.y;}

  bool operator<(Position2D p){return (pow(this->x, 2) + pow(this->y, 2)) < (pow(p.x, 2) + pow(p.y, 2));}
  bool operator>(Position2D p){return (pow(this->x, 2) + pow(this->y, 2)) > (pow(p.x, 2) + pow(p.y, 2));}

  bool operator==(Position2D p){return ((this->x == p.x) && (this->y == p.y));}
  bool operator!=(Position2D p){return ((this->x != p.x) && (this->y != p.y));}

  float getx() const {return x;}
  void setx(float x) {this->x = x;}

  float gety() const {return y;}
  void sety(float y) {this->y = y;}


private:
  float x;
  float y;
};

class Velocity2D
{
public:
  Velocity2D() : x(0.f), y(0.f){}
  Velocity2D(float x, float y) : x(x), y(y){}

  void operator+=(Velocity2D p){this->x+=p.x; this->y+=p.y;}
  void operator-=(Velocity2D p){this->x-=p.x; this->y-=p.y;}

  bool operator<(Velocity2D p){return (pow(this->x, 2) + pow(this->y, 2)) < (pow(p.x, 2) + pow(p.y, 2));}
  bool operator>(Velocity2D p){return (pow(this->x, 2) + pow(this->y, 2)) > (pow(p.x, 2) + pow(p.y, 2));}

  bool operator==(Velocity2D p){return ((this->x == p.x) && (this->y == p.y));}
  bool operator!=(Velocity2D p){return ((this->x != p.x) && (this->y != p.y));}

  float getx() const {return x;}
  void setx(float x) {this->x = x;}

  float gety() const {return y;}
  void sety(float y) {this->y = y;}

private:
  float x;
  float y;
};

class Acceleration2D
{
public:
  Acceleration2D() : x(0.f), y(0.f){}
  Acceleration2D(float x, float y) : x(x), y(y){}

  void operator+=(Acceleration2D p){this->x+=p.x; this->y+=p.y;}
  void operator-=(Acceleration2D p){this->x-=p.x; this->y-=p.y;}

  bool operator<(Acceleration2D p){return (pow(this->x, 2) + pow(this->y, 2)) < (pow(p.x, 2) + pow(p.y, 2));}
  bool operator>(Acceleration2D p){return (pow(this->x, 2) + pow(this->y, 2)) > (pow(p.x, 2) + pow(p.y, 2));}

  bool operator==(Acceleration2D p){return ((this->x == p.x) && (this->y == p.y));}
  bool operator!=(Acceleration2D p){return ((this->x != p.x) && (this->y != p.y));}

  float getx() const {return x;}
  void setx(float x) {this->x = x;}

  float gety() const {return y;}
  void sety(float y) {this->y = y;}

private:
  float x;
  float y;
};

Position2D operator+(Position2D a, Position2D b)
{
  return Position2D{a.getx() + b.getx(), a.gety() + b.gety()};
}

Position2D operator-(Position2D a, Position2D b)
{
  return Position2D{a.getx() - b.getx(), a.gety() - b.gety()};
}

Velocity2D operator+(Velocity2D a, Velocity2D b)
{
  return Velocity2D{a.getx() + b.getx(), a.gety() + b.gety()};
}

Velocity2D operator-(Velocity2D a, Velocity2D b)
{
  return Velocity2D{a.getx() - b.getx(), a.gety() - b.gety()};
}

Acceleration2D operator+(Acceleration2D a, Acceleration2D b)
{
  return Acceleration2D{a.getx() + b.getx(), a.gety() + b.gety()};
}

Acceleration2D operator-(Acceleration2D a, Acceleration2D b)
{
  return Acceleration2D{a.getx() - b.getx(), a.gety() - b.gety()};
}

Position2D operator*(Velocity2D v, DeltaSeconds dt)
{
  return Position2D{v.getx() * static_cast<float>(dt.count()), v.gety() * static_cast<float>(dt.count())};
}

Velocity2D operator*(Acceleration2D a, DeltaSeconds dt)
{
  return Velocity2D{a.getx() * static_cast<float>(dt.count()), a.gety() * static_cast<float>(dt.count())};
}

std::ostream& operator<<(std::ostream& stream, Position2D p)
{
  stream << "position2D={" << p.getx() << "," << p.gety() << "}" << std::endl;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, Velocity2D v)
{
  stream << "position2D={" << v.getx() << "," << v.gety() << "}" << std::endl;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, Acceleration2D a)
{
  stream << "position2D={" << a.getx() << "," << a.gety() << "}" << std::endl;
  return stream;
}

#endif
