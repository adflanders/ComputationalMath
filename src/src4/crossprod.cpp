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
  //cross product
  vector<double> y;


  //creates 2 random vectors.

  for(int i = 0; i < 3; i++){
    x.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
    b.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  for(int i = 0; i < x.size(); i++){
    cout << "x[" << i << "] = " << x[i] << "   |   ";
    cout << "b[" << i << "] = " << b[i] << endl;
  }

  y.push_back(x[1]*b[2]-x[2]*b[1]);
  y.push_back(x[2]*b[0]-x[0]*b[2]);
  y.push_back(x[0]*b[1]-x[1]*b[0]);

  cout << endl << "The cross product is:" << endl << endl;

  for(int i = 0; i < y.size(); i++){
    cout << "y[" << i << "] = " << y[i] << endl;
  }

  return 0;
}
