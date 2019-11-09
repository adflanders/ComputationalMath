# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_03.html)

* Notes for Dr. Koebbe: *temp*

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
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = 2x^3 + 3x - 3
// f'(x) = 6x^2 + 3

double function(double x){
  return x*x*x - x*x + 2;
}

double der(double x){
  return 3*x*x - 2*x;
}

int biNewton(double a, double b, int maxitter){

  double x0;
  double xn;

  if (function(a) * function(b) >= 0){

      cout << "You have not assumed right a and b\n";
      return 0;
  }

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
      if(abs(a-b)<1000){
        xn=a;
        x0=b;
        if(function(x0)==0.0){
          cout << "The root is: " << function(x0);
          return 0;
        }

        for(int j = 0; j < maxitter; j++){

        xn = x0 - function(x0)/der(x0);

        if(xn==x0){
        cout << "The root is: " << xn << " at the " << i+j << " itteration";
          return 0;
        }

        x0 = xn;
        cout << "current: " << xn << " i: " << i+j << endl << "---------" << endl;

        }

        cout << "The root is: " << xn << " at the " << maxitter+i << " itteration";

      }

   }

   return 0;

}


int main(){

biNewton(100000,-100000,100);

return 0;

}
