# Bisection routine:

**Purpose**
- Used for finding the root of a function f(x). How it works is testing between 2 initial points, a and b, then testing to see if
f(a)*f(b) < 0. If so, there is a root somewhere between the two points and the interval [a,b] becomes [a,c] such that c = (a+b)/2.
and then will make b = c. This shrinks the interval down until it finds the root to f(x).

**Input**
- Takes the initial guess a and b.

**Output**
- Returns the value of c once it has narrowed itself down past some epsilon.

**Code**
- [Bisection](https://github.com/adflanders/math4610/blob/master/src/bisect.cpp)
