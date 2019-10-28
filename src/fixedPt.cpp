#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.14159265;

double function(double x){

  double g = x - x*cosh(x) - x*x*x + pi;

  return g;

}

int main(){

double tmp = 0.0;
int maxItter = 50;

for(int i=0; i < maxItter; i++){

  tmp = function(tmp);
  cout << tmp << endl;
  cout << "i: " << i << endl << "----------" << endl;
}

return 0;
}
