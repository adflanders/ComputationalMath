# Secant method routine:

**Purpose**
- Used for finding the root of a function. Best used for when f'(x) is not know, or not wished to find. Iterates through the formula  

x2 = x1 - f(x1)[x1-x0]/(f(x1)-f(x0))

**Input**
- Takes the initial guess x0, a second intial guess x1, and a function f(x).

**Output**
- Returns a line for every iteration, showing what the last estimate was up to some fixed allowed max iteration.
If the max iteration is hit, it will display the final 'x2'

**Code**
- [Secant method](https://github.com/adflanders/math4610/blob/master/src/secant.cpp)
