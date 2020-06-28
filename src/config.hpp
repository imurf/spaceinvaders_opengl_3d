#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <chrono>

const unsigned int fps{60};

using DeltaSeconds = std::chrono::duration<double, std::ratio<1,1>>;
constexpr DeltaSeconds tick_period {1.0 / static_cast<double>(fps)};


#endif
