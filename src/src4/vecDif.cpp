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
    t.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  vector<double> dif;

  for(int i = 0; i < k.size(); i++){
    dif.push_back(k[i]-t[i]);
  }

  cout << "Difference of vectors k and i:\n" << "-----------------\n";

  for(int i = 0; i < dif.size(); i++){
    cout << dif[i] << endl;
  }

  return 0;
}
