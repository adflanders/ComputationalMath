#include <iostream>
#include <math.h>

using namespace std;

double function(double x){
  return 2*x*x*x + 3*x - 3;
}



int main(){

  int maxitter = 100;
  double x0 = 0.0;
  double x1 = 0.0;
  double xn = 0.0;

  cout << "Enter intial guess: ";
  cin >> x0;
  cout << endl;
  cout << "Enter second guess: ";
  cin >> x1;
  cout << endl;

  if(function(x0)==0.0){
    cout << "Root is: " << x0;
    return 0;
  }
  else if(function(x1)==0.0){
    cout << "Root is: " << x1;
    return 0;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

    if(xn==x1){
    cout << "The root is: " << xn << " at the " << i << " itteration";
      return 0;
    }

    x0 = x1;
    x1 = xn;

    cout << "current: " << xn << " i: " << i << endl << "---------" << endl;

  }

  cout << "The root is: " << xn << " at the " << maxitter << " itteration";

  return 0;
}
