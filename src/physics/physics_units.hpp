#ifndef _PHYICS_UNITS_HPP_
#define _PHYICS_UNITS_HPP_

constexpr float operator"" _meters(long double x)
{
  return static_cast<float>(x);
}

constexpr float operator"" _kilometers(long double x)
{
  return static_cast<float>(x * 1000.0);
}

constexpr float operator"" _meters_psec(long double x)
{
  return static_cast<float>(x);
}

constexpr float operator"" _kilometers_psec(long double x)
{
  return static_cast<float>(x * 1000.0);
}

constexpr float operator"" _meters_psec2(long double x)
{
  return static_cast<float>(x);
}

constexpr float operator"" _kilometers_psec2(long double x)
{
  return static_cast<float>(x * 1000.0);
}

#endif
