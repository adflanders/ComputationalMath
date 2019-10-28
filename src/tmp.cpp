#include <iostream>
#include <cmath>
using namespace std;

double pi = 3.14159265;

double f(double x)
{
  return x - x*cosh(x) - x*x*x + pi;
}

int main(){

  double p,p0=1,eps = 0.001;
  int i=1,N=50;

  while(i <= N)
  {
    p = f(p0);
    if(fabs(p-p0) < eps)
    {
      cout<<p<<endl;
      break;
    }
    cout<<"Iteration "<<i<<": p = "<<p<<endl;
    i++;
    p0 = p;
    cout<<"The solution is "<<p<<endl;
    if(i>N)
    {
      cout<<"Solution not found (method diverges)"<<endl;;
      break;
    }
  }
  cout<<"The approximated solution is x = "<<p<<" in the iteration "<<i-1<<endl;

  return 0;

  }
