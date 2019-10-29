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
=> f(x) = xcosh(x) + x^3 - pi  
=> x = x - f(x) = g(x)
=> g(x) = x - xcosh(x) - x^3 + pi
```
Now using 2 sets of fixed point iteration we will have
```
x1 = g(x0)
=> x2 = g(x1)
```
going until |x(k+1) - xk| < tolerance

**Task 3)**

```
#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.14159265;

double function(double x){

  double g = x - x*cosh(x) - x*x*x + pi;

  return g;

}

int main(){

double tmp = 0.0;
int maxItter = 50;

for(int i=0; i < maxItter; i++){

  tmp = function(tmp);
  cout << tmp << endl;
  cout << "i: " << i << endl << "----------" << endl;
}

return 0;
}
```
**Task 4)**
```
#include <iostream>

using namespace std;


double func(double x){
    return x*x*x - x*x + 2;
}

void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0){

        cout << "You have not assumed right a and b\n";
        return;
    }

    double eps = 0.0001;
    double c = a;
    while ((b-a) >= eps){

        c = (a+b)/2;

        if (func(c) == 0.0){
            break;
        }

        else if (func(c)*func(a) < 0){
            b = c;
        }

        else{
          a = c;
        }

    }
    cout << "The value of root is : " << c;
}

int main(){

    double a =-200, b = 300;
    bisection(a, b);

    return 0;
}

```
**Task 5)**
I have added the single and double machine precision routines to my [software manual page](https://github.com/adflanders/math4610/tree/master/Software-Manual)

**Task 6)**
I have added the absolute and relative error routines to my [software manual page](https://github.com/adflanders/math4610/tree/master/Software-Manual)

**Task 7)**
I added the fixed point iteration method to my [software manual page](https://github.com/adflanders/math4610/tree/master/Software-Manual)

**Task 8)**
I added the bisection method to my [software manual page](https://github.com/adflanders/math4610/tree/master/Software-Manual)

**Task 9)**
I found bisection to work faster and better, but only really faster if I had an adequate guess of where the interval should be and also to make sure it wasn't too large. Maybe it was partially due to how I coded both of them, but I also found the bisection to be more reliable/easier to work with.

**Task 10)**
[Cited Source](http://wwwf.imperial.ac.uk/metric/metric_public/numerical_methods/iteration/fixed_point_iteration.html):
