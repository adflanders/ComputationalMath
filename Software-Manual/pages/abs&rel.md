# Absolute error routine:

**Purpose**
- Used for finding the error in approximation for a solution when there is a known solution. Best used for larger numbers, otherwise
use the Relative error routine.

**Input**
- Takes in two values, the exact solution (j) and the estimated solution (k)

**Output**
- Returns the absolute distance between the two values |j-k|

**Code**
- [Absolute error](https://github.com/adflanders/math4610/blob/master/src/errabs.cpp)

# Relative error routine:

**Purpose**
- Used for finding the error in approximation for a solution when there is a known solution. Best used for smaller numbers, otherwise
use the Absolute error routine.

**Input**
- Takes in two values, the exact solution (j) and the estimated solution (k)

**Output**
- Returns the relative distance between the two values |j-k|/|j|

**Code**
- [Relative error](https://github.com/adflanders/math4610/blob/master/src/errrel.cpp)
