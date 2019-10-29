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
As expected, when it comes to speed alone, Fixed point <= Bisection < Secant method < Newtons method. This only holds true when both Secant and Newtons method are actually close to a root, otherwise they wont work and then cause the user to rely on Bisection and or Fixed point iteration to find the root, or get close enough for Secant or Newtons method to take over.
