#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <iostream>
#include <math.h>
#include <assert.h>

#include "math_defs.h"
#include "../typedefs.h"

struct Vector3
{
  real_t x = {0};
  real_t y = {0};
  real_t z = {0};

  /* constructors */

  _FORCE_INLINE_ Vector3(){}
  _FORCE_INLINE_ Vector3(real_t x, real_t y, real_t z) : x{x}, y{y}, z{z} {}
  _FORCE_INLINE_ Vector3(Vector2 v) : x{v.getx()}, y{v.gety()}{}

  /* methods */

  _FORCE_INLINE_ Vector3& normalize();
  _FORCE_INLINE_ Vector3 normalized() const;

  _FORCE_INLINE_ real_t length() const;
  _FORCE_INLINE_ real_t length_squared() const;

  _FORCE_INLINE_ void zero(){x = y = z = 0;}

  _FORCE_INLINE_ Vector3 cross(const Vector3& b) const;
  _FORCE_INLINE_ real_t dot(const Vector3& b) const;

  /* operators */

  _FORCE_INLINE_ Vector3& operator+=(const Vector3& b);
  _FORCE_INLINE_ Vector3 operator+(const Vector3& b) const;
  _FORCE_INLINE_ Vector3& operator-=(const Vector3& b);
  _FORCE_INLINE_ Vector3 operator-(const Vector3& b) const;
  _FORCE_INLINE_ Vector3& operator*=(const Vector3& b);
  _FORCE_INLINE_ Vector3 operator*(const Vector3& b) const;
  _FORCE_INLINE_ Vector3& operator/=(const Vector3& b);
  _FORCE_INLINE_ Vector3 operator/(const Vector3& b) const;

  _FORCE_INLINE_ Vector3& operator*=(real_t scalar);
  _FORCE_INLINE_ Vector3 operator*(real_t scalar) const;
  _FORCE_INLINE_ Vector3& operator/=(real_t scalar);
  _FORCE_INLINE_ Vector3 operator/(real_t scalar) const;

  _FORCE_INLINE_ Vector3 operator-() const;

  _FORCE_INLINE_ bool operator==(const Vector3& b) const;
  _FORCE_INLINE_ bool operator!=(const Vector3& b) const; 

  _FORCE_INLINE_ Vector3& operator=(const Vector3& b);

  /* mutators */

  _FORCE_INLINE_ void setx(real_t x) {x=x;}
  _FORCE_INLINE_ void sety(real_t y) {y=y;}
  _FORCE_INLINE_ void setz(real_t z) {z=z;}

  /* accessors */

  _FORCE_INLINE_ real_t getx() const {return x;}
  _FORCE_INLINE_ real_t gety() const {return y;}
  _FORCE_INLINE_ real_t getz() const {return z;}
};

std::ostream& operator<<(std::ostream& os, const Vector3& v);

Vector3& Vector3::normalize()
{
  real_t l = length_squared();
  if(l == 0) {
    x = y = z = 0;
  }
  else {
    l = 1 / sqrt(l); 
    x *= l;  
    y *= l;  
    z *= l;  
  }
  return *this;
}

Vector3 Vector3::normalized() const
{
  Vector3 v = *this;
  v.normalize();
  return v;
}

real_t Vector3::length() const
{
  return sqrt((x * x) + (y * y) + (z * z)); 
}

real_t Vector3::length_squared() const
{
  return (x * x) + (y * y) + (z * z);
}

Vector3 Vector3::cross(const Vector3& b) const
{
  return Vector3{
    ((y * b.z) - (z * b.y)),
    ((z * b.x) - (x * b.z)),
    ((x * b.y) - (y * b.x))
  };
}

real_t Vector3::dot(const Vector3& b) const
{
  return (x * b.x) + (y * b.y) + (z * b.z);
}

Vector3& Vector3::operator+=(const Vector3& b)
{
  x += b.x;
  y += b.y;
  z += b.z;
  return *this;
}

Vector3 Vector3::operator+(const Vector3& b) const
{
  return Vector3{
    (x + b.x),
    (y + b.y),
    (z + b.z)
  };
}

Vector3& Vector3::operator-=(const Vector3& b)
{
  x -= b.x;
  y -= b.y;
  z -= b.z;
  return *this;
}

Vector3 Vector3::operator-(const Vector3& b) const
{
  return Vector3{
    (x - b.x),
    (y - b.y),
    (z - b.z)
  };
}

Vector3& Vector3::operator*=(const Vector3& b)
{
  x *= b.x;
  y *= b.y;
  z *= b.z;
  return *this;
}

Vector3 Vector3::operator*(const Vector3& b) const
{
  return Vector3{
    (x * b.x),
    (y * b.y),
    (z * b.z)
  };
}

Vector3& Vector3::operator/=(const Vector3& b)
{
  x /= b.x;
  y /= b.y;
  z /= b.z;
  return *this;
}

Vector3 Vector3::operator/(const Vector3& b) const
{
  return Vector3{
    (x / b.x),
    (y / b.y),
    (z / b.z)
  };
}

Vector3& Vector3::operator*=(real_t scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  return *this;
}

// scalar multiplication is commutative 
_FORCE_INLINE_ Vector3 operator*(real_t scalar, const Vector3& b)
{
  return b * scalar;
}

Vector3 Vector3::operator*(real_t scalar) const
{
  return Vector3{
    (x * scalar),
    (y * scalar),
    (z * scalar)
  };
}

Vector3& Vector3::operator/=(real_t scalar)
{
  x /= scalar;
  y /= scalar;
  z /= scalar;
  return *this;
}

Vector3 Vector3::operator/(real_t scalar) const
{
  return Vector3{
    (x / scalar),
    (y / scalar),
    (z / scalar)
  };
}

Vector3 Vector3::operator-() const
{
  return Vector3{-x, -y, -z};
}

bool Vector3::operator==(const Vector3& b) const
{
  return (x == b.x) && (y == b.y) && (z == b.z);
}

bool Vector3::operator!=(const Vector3& b) const
{
  return (x != b.x) || (y != b.y) || (z != b.z);
}

Vector3& Vector3::operator=(const Vector3& b)
{
  x = b.x;
  y = b.y;
  z = b.z;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
  os << "vector3[" << &v       \
     << "]{x:" << v.getx()     \
     << ", y:" << v.gety()     \
     << ", z:" << v.getz()     \
     << "}"                    \
     << std::endl;
  return os;
}

#endif // _VECTOR3_H_
