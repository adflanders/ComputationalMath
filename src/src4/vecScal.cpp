#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;


int main(){

  vector<double> k;
  vector<double> t;
  srand(unsigned(time(NULL)));

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){
    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  double scal = (double)rand()/(RAND_MAX + 1.0)+1+(rand()%5);

  for(int i = 0; i < k.size(); i++){
    k[i] = k[i]*scal;
  }

  cout << "Scalar multiple of vector k:\n" << "-----------------\n";
  cout << "Scalar: " << scal << endl;

  for(int i = 0; i < k.size(); i++){
    cout << k[i] << endl;
  }

  return 0;
}
