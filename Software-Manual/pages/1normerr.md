# 1-Norm with relative error and absolute error between two vectors, x and x*

* x is a random vector of size 10, with random numbers between (0,11) with up to 4 decimal places. x* is the components of x rounded to the nearest whole number, acting as an estimate.
- 1-Norm is the sum of the magnitudes of the vectors in a space. It can be written as  
|x| = |x1| + |x2| + ... + |xn|

for absolute error we will have |x|-|x*|  
for relative error we will have (|x|-|x*|)/|x| 

## Input

- the 1-norm calculates the vector x and x*, then relative and absolute error routines compare the two.  


## Output

- Returns the 1-norm of x, x*, and depending on the code used below, will also dispay either the relative or absolute error between the two.

# Code

- 1-norm

[absolute error](https://github.com/adflanders/math4610/blob/master/src/src4/absnorm1.cpp)

[relative error](https://github.com/adflanders/math4610/blob/master/src/src4/relnorm1.cpp)
