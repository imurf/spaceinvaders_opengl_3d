#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include <math.h>

namespace math
{
namespace vector
{

namespace vector_type
{
enum type {direction, point};
}

template<typename T>
class Vector3
{
public:
  Vector3() : x{0}, y{0}, z{0}, w{1}{}
  Vector3(T x, T y, T z, enum vector_type::type w = vector_type::point) : x{x}, y{y}, z{z}, w{static_cast<T>(w)}{}

  void normalize();
  void uniform_scale(T s);

  T length() const;
  T length_squared() const;

  void operator+=(Vector3 b);
  void operator-=(Vector3 b);

  bool operator==(Vector3 b) const;
  bool operator!=(Vector3 b) const; 

  void operator=(Vector3 b);

  T getx() const {return x;}
  T gety() const {return y;}
  T getz() const {return z;}
  T getw() const {return w;}

  void setx(T x) {this->x=x;}
  void sety(T y) {this->y=y;}
  void setz(T z) {this->z=z;}
  void setw(enum vector_type w) {this->w=w;}

private:
  T x;
  T y;
  T z;
  enum vector_type::type w;
};

template<typename T>
void Vector3<T>::normalize()
{
  T invlen = static_cast<T>(1) / this->length();
  this->x *= invlen;
  this->y *= invlen;
  this->z *= invlen;
}

template<typename T>
void Vector3<T>::uniform_scale(T s)
{
  this->x *= s;
  this->y *= s;
  this->z *= s;
}

template<typename T>
T Vector3<T>::length() const
{
  return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z)); 
}

template<typename T>
T Vector3<T>::length_squared() const
{
  return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

template<typename T>
void Vector3<T>::operator+=(Vector3<T> b)
{
  assert(!(this->w == vector_type::point && b.getw() == vector_type::point));
  this->x += b.getx();
  this->y += b.gety();
  this->z += b.getz();
  this->w += b.getw();
}

template<typename T>
void Vector3<T>::operator-=(Vector3<T> b)
{
  assert(!(this->w == vector_type::direction && b.getw() == vector_type::point));
  this->x -= b.getx();
  this->y -= b.gety();
  this->z -= b.getz();
  this->w -= b.getw();
}

template<typename T>
Vector3<T> operator+(Vector3<T> a, Vector3<T> b)
{
  assert(!(a.getw() == vector_type::point && b.getw() == vector_type::point));
  return Vector3<T>{
    a.getx() + b.getx(),
    a.gety() + b.gety(),
    a.getz() + b.getz(),
    a.getw() + b.getw()};
}

template<typename T>
Vector3<T> operator-(Vector3<T> a, Vector3<T> b)
{
  assert(!(a.getw() == vector_type::direction && b.getw() == vector_type::point));
  return Vector3<T>{
    a.getx() - b.getx(),
    a.gety() - b.gety(),
    a.getz() - b.getz(),
    a.getw() - b.getw()};
}

template<typename T>
bool Vector3<T>::operator==(Vector3<T> b) const
{
  // TODO: approx equal
  //https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
}

template<typename T>
bool Vector3<T>::operator!=(Vector3<T> b) const
{
  // approx not equal
}

template<typename T>
void Vector3<T>::operator=(Vector3<T> b)
{
  this->x = b.getx();
  this->y = b.gety();
  this->z = b.getz();
  this->w = b.getw();
}

template<typename T>
T dot(Vector3<T> a, Vector3<T> b)
{
  return (a.getx() * b.getx()) + (a.gety() * b.gety()) + (a.getz() * b.getz());
};

template<typename T>
Vector3<T> cross(Vector3<T> a, Vector3<T> b)
{
  return Vector3<T>{
    ((a.gety() * b.getz()) - (a.getz() * b.gety())),
   -((a.getx() * b.getz()) - (a.getz() * b.getx())),
    ((a.getx() * b.gety()) - (a.gety() * b.getx())),
    (a.getw() * b.getw())
  };
}

template<typename T>
Vector3<T> uniform_scale(Vector3<T> a, T s)
{
  return Vector3<T>{
    a.getx() * s,
    a.gety() * s,
    a.getz() * s,
    a.getw()
  };
}

template<typename T>
Vector3<T> normalized(Vector3<T> a)
{
  T invlen = static_cast<T>(1) / a.length();
  return Vector3<T>{
    a.getx() * invlen,
    a.gety() * invlen,
    a.getz() * invlen,
    a.getw()
  };
}

using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;

}
}

#endif
