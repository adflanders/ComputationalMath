#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
  srand(unsigned(time(NULL)));

  //setting up dot product between two random vectors

  //vector x
  vector<double> x;
  //vector b
  vector<double> b;
  //dot product
  double dot = 0;


  //creates 2 random vectors.

  for(int i = 0; i < 3; i++){

    x.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

    b.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

  }

  for(int i = 0; i < x.size(); i++){
    dot = x[i]*b[i] + dot;
    cout << "x[" << i << "] = " << x[i] << "   |   ";
    cout << "b[" << i << "] = " << b[i] << endl;
  }

  cout << "The dot product is: " << dot;

  return 0;
}
