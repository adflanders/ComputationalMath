#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.1415926535897932;

double function(double x){
  return sin(pi*x*x+3.7);
}

double der(double x){
  return cos(pi*x*x+3.7)*2*pi*x;
}

double newton(double x0){

  int maxitter = 100;
  double xn = 0.0;
  double eps = 0.000001;


  if(function(x0)==0.0){
    return x0;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x0 - function(x0)/der(x0);

    if(abs(xn-x0) < eps){
      return xn;
    }

    x0 = xn;

  }
  return xn;
}

int main(){

  double a = 1.1;
  double b = 68.3;

  return 0;

}
