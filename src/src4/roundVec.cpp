#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(){

  vector<double> k;
  srand(unsigned(time(NULL)));

  //creates random vector WITH decimals.

  for(int i = 0; i < 8; i++){

    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
    cout << k[i] << endl;

  }


  return 0;
}
