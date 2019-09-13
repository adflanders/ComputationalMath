#include <iostream>

using namespace std;

int main(){

  double one = 1.0;
  double eps = 2.0;
  double diff;

  for(int i=0;i<1000;i++){
    diff = one - (one + eps);
    if(diff==0){
      cout << "final epsilon: " << eps << endl << "final iteration: " << i;
      return 0;
    }

    eps *= 0.5;

  }

  return 0;
}
