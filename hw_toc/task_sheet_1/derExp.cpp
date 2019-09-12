//for the fuction f(x) =  e^(x)

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
    cout << "f'(x) = e^(x) => f'(1) = e = " << exp(1) << endl << endl;
    double y = 1.0;
    double k;
    k = 1.0;
    int iter = 1;
    while(exp(1.0) != compErr(y,k) && iter <= 60){

      cout << "Iteration: " << iter << endl;
      cout << compErr(y,k) << endl;
      cout << "-------------------" << endl;
      k = k * 0.75;
      iter++;

    }


return 0;
}
