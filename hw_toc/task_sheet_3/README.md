# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_03.html)

* Notes for Dr. Koebbe: For the hybrid methods, k is used as a starting point for the bisection method and is shrunk down when newton and/or secant method cant work, narrowing down when they are efficient.

**Task 1)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = 2x^3 + 3x - 3
// f'(x) = 6x^2 + 3

double function(double x){
  return 2*x*x*x + 3*x - 3;
}

double der(double x){
  return 6*x*x + 3;
}

int main(){

int maxitter = 100;
double x0 = 0.0;
double xn = 0.0;
double error;

cout << "Enter intial guess: ";
cin >> x0;
cout << endl;

if(function(x0)==0.0){
  cout << "The root is: " << function(x0);
  return 0;
}

for(int i = 0; i < maxitter; i++){

xn = x0 - function(x0)/der(x0);

if(xn==x0){
cout << "The root is: " << xn << " at the " << i << " itteration";
  return 0;
}

error = abs(xn-x0);
x0 = xn;
cout << "current: " << xn << " i: " << i << endl << "---------" << endl;

}

cout << "The root is: " << xn << " at the " << maxitter << " itteration";

return 0;
}
```
**Task 2)**
```
#include <iostream>
#include <math.h>

using namespace std;

double function(double x){
  return 2*x*x*x + 3*x - 3;
}



int main(){

  int maxitter = 100;
  double x0 = 0.0;
  double x1 = 0.0;
  double xn = 0.0;

  cout << "Enter intial guess: ";
  cin >> x0;
  cout << endl;
  cout << "Enter second guess: ";
  cin >> x1;
  cout << endl;

  if(function(x0)==0.0){
    cout << "Root is: " << x0;
    return 0;
  }
  else if(function(x1)==0.0){
    cout << "Root is: " << x1;
    return 0;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

    if(xn==x1){
    cout << "The root is: " << xn << " at the " << i << " itteration";
      return 0;
    }

    x0 = x1;
    x1 = xn;

    cout << "current: " << xn << " i: " << i << endl << "---------" << endl;

  }

  cout << "The root is: " << xn << " at the " << maxitter << " itteration";

  return 0;
}
```
**Task 3)**
I viewed how many iterations it took for the methods to solve the roots of f(x) = x^3 - x^2 + 2.
* Newtons method: 5 iterations
* Secant method: 10 iterations
* Bisection: 34 iterations
* Fixed point: 42 iterations
it should be noted that these methods do depend on a starting place, so I made sure to have all the starting conditions start relatively close to the root of f(x) which is -1

**Task 4)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = x^3 - x^2 + 2
// f'(x) = 3x^2 - 2x

double function(double x){
  return x*x*x - x*x + 2;
}

double der(double x){
  return 3*x*x - 2*x;
}

int biNewton(double a, double b, int maxitter){

  double x0;
  double xn;
  double k = abs(a)+abs(b);
  k = k/2;

  int i = 0;
  double eps = 0.0001;
  double c = a;

  while (abs(b-a) > eps){
      c = (a+b)/2;
      i++;
      if (function(c) == 0.0){
        cout << "Solution is " << c << " at iteration " << i;
          break;
      }

      else if (function(c)*function(a) < 0){
          b = c;
      }

      else{
        a = c;
      }
      if(abs(a-b)<k){

        x0 = a;

        if(function(x0)==0.0){
          cout << "The root is: " << x0;
          return 0;
        }

        for(int j = 0; j < maxitter; j++){

          xn = x0 - function(x0)/der(x0);

          if(xn==x0){
          cout << "The FINAL root is: " << xn << " at the " << i+j << " itteration";
            return 0;
          }

          if(abs(a-b)<abs(x0-xn)){
            cout << "The root is: " << xn << " at the " << i+j << " itteration" << endl;
            cout << "----------------" << endl;
            k = k/10;
            break;
          }

          x0 = xn;

        }

      }

   }

   return 0;

}


int main(){

biNewton(100000,-100000,100);

return 0;

}
```

- Converges in 23 iterations to -1 (correct)

**Task 5)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = x^3 - x^2 + 2

double function(double x){
  return x*x*x - x*x + 2;
}

int biSecant(double a, double b, int maxitter){

  double x0;
  double x1;
  double xn;

  if (function(a) * function(b) >= 0){

      cout << "You have not assumed right a and b\n";
      return 0;
  }

  // k is just the middle point of a and b
  double k = abs(a)+abs(b);
  k = k/2;

  int i = 0;
  double eps = 0.0001;
  double c = a;

  while (abs(b-a) > eps){
      c = (a+b)/2;
      i++;
      if (function(c) == 0.0){
        cout << "Solution is " << c << " at iteration " << i;
          break;
      }

      else if (function(c)*function(a) < 0){
          b = c;
      }

      else{
        a = c;
      }

      if(abs(a-b)<k){

        x0=a;
        x1=b;

        if(function(x0)==0.0){
          cout << "Root is: " << x0;
          return 0;
        }

        else if(function(x1)==0.0){
          cout << "Root is: " << x1;
          return 0;
        }

        for(int j = 0; j < maxitter; j++){

          xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

          if(xn==x1){
          cout << "The FINAL root is: " << xn << " at the " << i+j << " itteration";
            return 0;
          }

          x0 = x1;
          x1 = xn;
          
          if(abs(a-b)<abs(x0-x1)){
            cout << "The root is: " << xn << " at the " << i+j << " itteration" << endl;
            cout << "----------------" << endl;
            k = k/10;
            break;
          }

        }

      }

   }

   return 0;

}


int main(){

biSecant(100000,-100000,100);

return 0;

}

```


- Converges in 25 iterations to -1 (correct)

**Task 6)**
Code placed in my [Software-manual](https://github.com/adflanders/math4610/blob/master/Software-Manual/README.md), implenting my code directly to other tasks and not using shared library as it is not working.

**Task 7)**

```
#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.1415926535897932;

double func(double x){
    return sin(pi*x*x+3.7);
}

double bisection(double a, double b){

    int i = 0;
    double eps = 0.000001;
    double c = a;
    while ((b-a) >= eps){

        c = (a+b)/2;
        i++;
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
    return c;
}

int main(){

    int maxiter = 1000;
    int root = 0;
    double a = 1.1, b = 68.3;
    while (a != bisection(a,b) || root < maxiter){
      if(a == bisection(a,b)){
        break;
      }
      root++;
      cout << bisection(a,b) << " is a root. #" << root << endl;
      cout << "--------------------\n";
      a = bisection(a,b);


    }

    return 0;
}
```
- output:  
1.34991 is a root. #1  
20.1946 is a root. #2  
31.0133 is a root. #3  
51.0864 is a root. #4  
67.7777 is a root. #5  
68.2336 is a root. #6  
68.2482 is a root. #7  
68.2922 is a root. #8  
68.2995 is a root. #9  
68.3 is a root. #10  


