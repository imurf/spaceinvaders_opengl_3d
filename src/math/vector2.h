#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

// TODO:
//
// - can simplify this further by removing the templates and just using floats, since I only 
//   need floats, I am actually overabstracting by creating code (i.e. double versions) that I
//   will not use. Thus remove the templates and rename Vector2D

#include <math.h>

namespace math
{
namespace vector
{

template<typename T>
class Vector2
{
public:
  Vector2() : x{0}, y{0}, w{1}{}
  Vector2(T x, T y, enum vector_type::type w = vector_type::point) : x{x}, y{y}, z{z}, w{static_cast<T>(w)}{}

  void normalize();
  void uniform_scale(T s);

  T length() const;
  T length_squared() const;

  void operator+=(Vector2 b);
  void operator-=(Vector2 b);

  bool operator==(Vector2 b) const;
  bool operator!=(Vector2 b) const; 

  void operator=(Vector2 b);

  T getx() const {return x;}
  T gety() const {return y;}
  T getw() const {return w;}

  void setx(T x) {this->x=x;}
  void sety(T y) {this->y=y;}
  void setw(enum vector_type w) {this->w=w;}

private:
  T x;
  T y;
  enum vector_type::type w;
};

template<typename T>
void Vector2<T>::normalize()
{
  T invlen = static_cast<T>(1) / this->length();
  this->x *= invlen;
  this->y *= invlen;
}

template<typename T>
void Vector2<T>::uniform_scale(T s)
{
  this->x *= s;
  this->y *= s;
}

template<typename T>
T Vector2<T>::length() const
{
  return sqrt((this->x * this->x) + (this->y * this->y)); 
}

template<typename T>
T Vector2<T>::length_squared() const
{
  return (this->x * this->x) + (this->y * this->y);
}

template<typename T>
void Vector2<T>::operator+=(Vector2<T> b)
{
  assert(!(this->w == vector_type::point && b.getw() == vector_type::point));
  this->x += b.getx();
  this->y += b.gety();
  this->w += b.getw();
}

template<typename T>
void Vector2<T>::operator-=(Vector2<T> b)
{
  assert(!(this->w == vector_type::direction && b.getw() == vector_type::point));
  this->x -= b.getx();
  this->y -= b.gety();
  this->w -= b.getw();
}

template<typename T>
Vector2<T> operator+(Vector2<T> a, Vector2<T> b)
{
  assert(!(a.getw() == vector_type::point && b.getw() == vector_type::point));
  return Vector2<T>{
    a.getx() + b.getx(),
    a.gety() + b.gety(),
    a.getw() + b.getw()};
}

template<typename T>
Vector2<T> operator-(Vector2<T> a, Vector2<T> b)
{
  assert(!(a.getw() == vector_type::direction && b.getw() == vector_type::point));
  return Vector2<T>{
    a.getx() - b.getx(),
    a.gety() - b.gety(),
    a.getw() - b.getw()};
}

template<typename T>
bool Vector2<T>::operator==(Vector2<T> b) const
{
  // TODO: approx equal
  //https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
}

template<typename T>
bool Vector2<T>::operator!=(Vector2<T> b) const
{
  // approx not equal
}

template<typename T>
void Vector2<T>::operator=(Vector2<T> b)
{
  this->x = b.getx();
  this->y = b.gety();
  this->w = b.getw();
}

template<typename T>
T dot(Vector2<T> a, Vector2<T> b)
{
  return (a.getx() * b.getx()) + (a.gety() * b.gety());
};

template<typename T>
T cross(Vector2<T> a, Vector2<T> b)
{
  return ((a.getx() * b.gety()) - (a.gety() * b.getx()));
}

template<typename T>
Vector2<T> uniform_scale(Vector2<T> a, T s)
{
  return Vector2<T>{
    a.getx() * s,
    a.gety() * s,
    a.getw()
  };
}

template<typename T>
Vector2<T> normalized(Vector2<T> a)
{
  T invlen = static_cast<T>(1) / a.length();
  return Vector2<T>{
    a.getx() * invlen,
    a.gety() * invlen,
    a.getw()
  };
}

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

}
}

#endif
