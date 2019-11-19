#include <iostream>
#include <math.h>

using namespace std;

double function(double x){
  return 2*x*x*x + 3*x - 3;
}

double secant(double x0, double x1){

  int maxitter = 1000;
  double xn = 0.0;
  double eps = 0.00001;

  if(function(x0)<eps){
    return x0;
  }
  else if(function(x1)<eps){
    return x1;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

    if(abs(xn-x1)<eps){
      return xn;
    }

    x0 = x1;
    x1 = xn;

  }

  return xn;

}

int main(){

  int root = 0;
  int maxiter = 1000;
  double a = 1.1;
  double b = 68.3;
  double tmpA;
  double tmpB;

   while(a <= b && root < maxiter){
    if(secant(a,a+1) < 1.1){
      a++;
      cout << a << endl;
    }
    else if(secant(a,a+1) > a){
      root++;
      cout << secant(a,a+1) << " is a root. #" << root << endl;
      cout << "---------------------\n";
      cout << a << endl;
      a++;
    }

  }

  return 0;

}
