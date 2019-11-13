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
