#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void norm2(vector<double> &k){

  double sum = 0.0;
  for(int i = 0; i < k.size(); i++){
    sum = sum + k[i]*k[i];
  }
  cout << sqrt(sum);

}

int main(){

  vector<double> k;
  k.push_back(3);
  k.push_back(4.2);

  norm2(k);

  return 0;

}
