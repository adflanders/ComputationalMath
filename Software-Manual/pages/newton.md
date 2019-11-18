# Newton method routine:

**Purpose**
- Used for finding the root of a function. Uses a function f(x) and its derivative f'(x) and finds the root x(k+1) by using the formula;
x(k+1) = xk - f(xk)/f'(xk). Then loops through till x(k+1) ~= xk.

**Input**
- Takes the initial guess (xk), f(x) and f'(x).

**Output**
- Returns a line for every iteration, showing what the last estimate was up to some fixed allowed max iteration.

**Code**
- [Newtons method](https://github.com/adflanders/math4610/blob/master/src/newton.cpp)
