#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.1415926535897932384626433;

double equation(double x){

  double eq = x - x*cosh(x) + pow(x,3) - pi;

  return eq;
}

int main(){

double tol = .0001;
double tmp1 = 0;
double tmp2;

for(int i = 0; i < 50; i++){

tmp2 = tmp1;
tmp1 = equation(tmp2);

/*if(abs(tmp1-tmp2) < tol){
  cout << "The root is: " << tmp1;
  return 0;
}*/

cout << "The root is: " << tmp1 << " for i = " << i << endl;

}



return 0;
}
