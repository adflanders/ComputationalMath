# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_02.html)

* Notes for Dr. Koebbe: *temp*

**Task 1)** for
```
xcos(x) + x^3 = pi  
```
find a value x' such that
```
x'cos(x') + x'^3 - pi = 0
```

**Task 2)** Setting up 2 fixed point iterations first requires finding some g(x)
such that
```
xcos(x) + x^3 = pi
=> f(x) = xcos(x) + x^3 - pi  
=> x = x - f(x) = g(x)
=> g(x) = x - xcos(x) - x^3 + pi
```
Now using 2 sets of fixed point iteration we will have
```
x1 = g(x0)
=> x2 = g(x1)
```
going until |x(k+1) - xk| < tolerance

**Task 3)**
