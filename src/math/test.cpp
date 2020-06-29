
#include <iostream>
#include "vector3.h"

using namespace std;

int main()
{
  Vector3 a{1.5, 2.5, 3.5, Vector3::point};
  Vector3 b{4.5, 5.5, 6.5, Vector3::direction};
  std::cout << a << b << std::endl; 

  Vector3 c{};

  cout << "c = b" << endl;
  cout << (c = b) << endl;

  cout << "c + a" << endl;
  cout << (c + a) << endl;

  cout << "a - b" << endl;
  cout << (a - b) << endl;

  cout << "c = a + b" << endl;
  cout << (c = a + b) << endl;

  cout << "c.normalized()" << endl;
  cout << (c.normalized()) << endl;

  cout << "c.normalize()" << endl;
  cout << (c.normalize()) << endl;

  cout << "c.length()" << endl;
  cout << (c.length()) << endl;

  cout << "c.length_squared()" << endl;
  cout << (c.length_squared()) << endl;

  cout << "c = Vector3{1, 0, 0}" << endl;
  cout << (c = Vector3{1, 0, 0}) << endl;

  cout << "c.cross(Vector3{0, 1, 0))" << endl;
  cout << (c.cross(Vector3{0, 1, 0})) << endl;

  cout << "a.dot(b)" << endl; 
  cout << (a.dot(b)) << endl; 

  cout << "c = b" << endl;
  cout << (c = b) << endl;

  cout << "c * 2.f" << endl;
  cout << (c * 2.f) << endl;

}
