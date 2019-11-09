#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = 2x^3 + 3x - 3
// f'(x) = 6x^2 + 3

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

      if(abs(a-b)<10){

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
          cout << "The root is: " << xn << " at the " << i+j << " itteration";
            return 0;
          }

          x0 = x1;
          x1 = xn;

          cout << "current: " << xn << " i: " << i+j << endl << "---------" << endl;

        }

        cout << "The root is: " << xn << " at the " << maxitter+i << " max allowed itteration";

        return 0;


      }

   }

   return 0;

}


int main(){

biSecant(100000,-100000,100);

return 0;

}
