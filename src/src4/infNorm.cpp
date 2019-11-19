#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void infNorm(vector<double> &k){

  double tmp = 0.0;
  for(int i = 0; i < k.size(); i++){
    if(tmp < k[i]){
      tmp = k[i];
    }
  }
  cout << tmp;

}

int main(){

  vector<double> k;
  k.push_back(3);
  k.push_back(4.2);
  k.push_back(19.3);
  k.push_back(7.7);

  infNorm(k);

  return 0;

}
