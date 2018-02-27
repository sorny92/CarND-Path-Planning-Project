/*
** 
** CarND-Path-Planning-Project
** File description:
** utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <math.h>

// For converting back and forth between radians and degrees.
constexpr double pi() { return M_PI; }
constexpr double deg2rad(double x) { return x * pi() / 180; }
constexpr double rad2deg(double x) { return x * 180 / pi(); }


#endif /* !UTILS_HPP_ */
