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
