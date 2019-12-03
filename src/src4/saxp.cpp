#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double errrel(double j, double k){

double m = abs(j - k);
double t = m/j;

return t;
}

int main(){
  srand(unsigned(time(NULL)));

  //setting up y = mx + b. y,x,b are vectors, m is a scalar

  //vector x
  vector<double> x;
  //vector b
  vector<double> b;
  //vector y
  vector<double> y;
  //scalar m
  double m = rand()%5;

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){

    x.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

    b.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

  }

  for(int i = 0; i < x.size(); i++){
    y.push_back(m*x[i] + b[i]);
    cout << "y[" << i << "] = " << y[i] << endl;
  }


  return 0;
}
