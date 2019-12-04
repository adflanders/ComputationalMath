#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
  srand(unsigned(time(NULL)));

  //matrix x
  vector<double> x;
  //vector a
  double a[3][3];
  //vector y
  double y[3] = {0,0,0};

  //creates the matrix (a) and vector (b)
cout << "A = " << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      a[i][j] = (double)rand()/(RAND_MAX + 1.0)+1+(rand()%10);
    }
    x.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
    cout << a[i][0] << "  " << a[i][1] << "  " << a[i][2] << endl;
  }

  cout << endl << "x = " << endl;
  for(int i = 0; i < 3; i++){
    cout << x[i] << endl;
  }

  cout << endl << "y = " << endl;
  //does the multiplication and creates y
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      y[i] = x[j]*a[i][j] + y[i];
    }
    cout << y[i] << endl;
  }

  return 0;
}
