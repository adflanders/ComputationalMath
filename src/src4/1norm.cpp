#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void norm1(vector<double> &k){

  double sum = 0.0;
  for(int i = 0; i < k.size(); i++){
    sum = sum + k[i];
  }
  cout << sum;

}

int main(){

  vector<double> k;
  k.push_back(12.3);
  k.push_back(7.1);

  norm1(k);

  return 0;

}
