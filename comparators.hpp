

/*
  comparators.hpp
  functions for comparing values
*/

#ifndef COMPARATORS_HPP
#define COMPARATORS_HPP

template <typename T>
__attribute__ ((pure)) inline T min (T a, T b) {
    return a < b ? a : b;
}

template <typename T>
__attribute__ ((pure)) inline T max (T a, T b) {
    return a > b ? a : b;
}

#endif
