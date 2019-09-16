//for the fuction f(x) =  e^(x)
#include "src.h"
#include <iostream>
#include <math.h>

using namespace std;

const double pi = 3.14159265358979323846264338327950288419716;

double compErr(float x, float h){

    double function = (exp(x+h)-exp(x-h))/((x+h)-(x-h));

  return function;
}


int main(){

    cout << endl << "f(x) = e^(x)" << endl;
    cout << "f'(x) = e^(x) => f'(1) = e = " << exp(pi) << endl << endl;
    double y = pi;
    double k;
    k = 1.0;
    int iter = 1;
    while(exp(pi) != compErr(y,k) && iter <= 60){

      cout << "Iteration: " << iter << endl;
      cout << compErr(y,k) << endl;
      cout << "-------------------" << endl;
      k = k * 0.75;
      iter++;

    }

    // for k = 21 (21st Iteration) is closely approximated to exp(pi)

    k = pow(0.75,21);
    
    errabs(compErr(y,k),exp(pi));
    errrel(compErr(y,k),exp(pi));
    smaceps();


return 0;
}
