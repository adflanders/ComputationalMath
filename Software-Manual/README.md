# Math 4610 software manual

Table of contents that can guide the user throughout all the code/programs contained in this repository.

## Basic Routines

The basic routines and methods/functions that will be used throughout this course.
### Shared library containing functions such as,

* smaceps
* dmaceps
* absolute error
  - shows exactly how far off an estimate is by the form of |x-x*|
* relative error
  - shows how relatively far off an estimate is by the form of |x-x*|/x
  and gives back a percentage. This is best used for bigger numbers. 

Can be found  [here](https://github.com/adflanders/math4610/tree/master/srcLibrary)

## Root Finding Routines
* [Fixed point](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/fixedPoint.md)
* [Bisection](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/bisection.md)
* [Newtons method](https://github.com/adflanders/math4610/blob/master/src/newton.cpp)
* [Secant method](https://github.com/adflanders/math4610/blob/master/src/secant.cpp)
* [Hybrid method with bisection and newtons method](https://github.com/adflanders/math4610/blob/master/src/biNewton.cpp)
* [Hybrid method with bisection and secant method](https://github.com/adflanders/math4610/blob/master/src/biSecant.cpp)
