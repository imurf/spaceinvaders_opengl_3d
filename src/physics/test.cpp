#include <iostream>
#include "../config.hpp"
#include "physics_types.hpp"
#include "physics_units.hpp"


int main()
{
  Position2D pos;
  Velocity2D vel{0.0_meters_psec, 10.0_meters_psec};

  for(int i = 0; i < 10; ++i)
  {
    pos += vel * tick_period;
    std::cout << pos;
  }
}

