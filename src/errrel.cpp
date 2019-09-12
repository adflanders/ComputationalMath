#include <iostream>
#include <math.h>

using namespace std;

//function that computes Relative error. raw value, not percentage

double errrel(double j, double k){

double m = abs(j - k);
double t = m/j;

return t;
}
