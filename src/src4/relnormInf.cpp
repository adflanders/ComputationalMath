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

  //actual generated vector
  vector<double> k;
  //rounded off 'estimated' vector
  vector<double> t;

  srand(unsigned(time(NULL)));

  //creates random vector WITH decimals, then makes one rounded off i.e 'estimated'.

  for(int i = 0; i < 8; i++){

    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

    t.push_back(round(k[i]));

  }

  double maxK = 0.0;
  double maxT = 0.0;

  for(int i = 0; i < k.size(); i++){
    if(maxK<k[i]){
      maxK = k[i];
    }
  }
  cout << "Actual Inf-norm: " << maxK << endl;

  for(int i = 0; i < t.size(); i++){
    if(maxT<t[i]){
      maxT = t[i];
    }
  }
  cout << "Estimated Inf-norm: " << maxT << endl;

  cout << errrel(maxK, maxT) << " is the relative error.";

  return 0;
}
