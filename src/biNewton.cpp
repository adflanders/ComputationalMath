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
        cout << "current: " << xn << " iteration: " << i+j << endl << "---------" << endl;

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
