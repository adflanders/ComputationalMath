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
