#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double errabs(double j, double k){

double m = abs(j - k);

return m;
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

  double sumK = 0.0;
  double sumT = 0.0;

  for(int i = 0; i < k.size(); i++){
    sumK = sumK + k[i];
  }
  cout << "Actual norm1: " << sumK << endl;

  for(int i = 0; i < t.size(); i++){
    sumT = sumT + t[i];
  }
  cout << "Estimated norm1: " << sumT << endl;

  cout << errabs(sumK, sumT) << " is the absolute error.";

  return 0;
}
