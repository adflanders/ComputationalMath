# Fixed point iteration routine:

**Purpose**
- Used for finding the root of a function. How it works is setting the function f(x) as g(x) = x - f(x) = x.
Use an intial guess x0 such that x1 = g(x0). Iterate down to xn where xn = g(x(n-1)).

**Input**
- Takes the initial guess (x0).

**Output**
- Returns a line for every iteration, showing what the last estimate was up to some fixed allowed max iteration.

**Code**
- [Fixed point iteration](https://github.com/adflanders/math4610/blob/master/src/fixedPt.cpp)
