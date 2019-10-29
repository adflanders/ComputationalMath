#include <iostream>

using namespace std;


double func(double x){
    return x*x*x - x*x + 2;
}

void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0){

        cout << "You have not assumed right a and b\n";
        return;
    }

    int i = 0;
    double eps = 0.0001;
    double c = a;
    while ((b-a) >= eps){

        c = (a+b)/2;
        i++;
        if (func(c) == 0.0){
            break;
        }

        else if (func(c)*func(a) < 0){
            b = c;
        }

        else{
          a = c;
        }

    }
    cout << "The value of root is : " << c << ". at i = " << i;
}

int main(){

    double a =-200, b = 300;
    bisection(a, b);

    return 0;
}
