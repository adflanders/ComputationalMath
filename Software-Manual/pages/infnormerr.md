# inf-Norm with relative error and absolute error between two vectors, x and x*

* x is a random vector of size 10, with random numbers between (0,11) with up to 4 decimal places. x* is the components of x rounded
to the nearest whole number, acting as an estimate.

- inf-Norm is the largest component in magnitude from the vector.

for absolute error we will have |x|-|x*|  
for relative error we will have (|x|-|x*|)/|x| 

## Input

- the inf-norm calculates the vector x and x*, then relative and absolute error routines compare the two.  


## Output

- Returns the inf-norm of x, x*, and depending on the code used below, will also dispay either the relative or absolute error between the two.

# Code

- inf-norm

[absolute error](https://github.com/adflanders/math4610/blob/master/src/src4/absnorminf.cpp)

[relative error](https://github.com/adflanders/math4610/blob/master/src/src4/relnorminf.cpp)
