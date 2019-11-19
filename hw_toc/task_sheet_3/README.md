# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_03.html)

* Notes for Dr. Koebbe: For the hybrid methods, k is used as a starting point for the bisection method and is shrunk down when newton and/or secant method cant work, narrowing down when they are efficient.

**Task 1)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = 2x^3 + 3x - 3
// f'(x) = 6x^2 + 3

double function(double x){
  return 2*x*x*x + 3*x - 3;
}

double der(double x){
  return 6*x*x + 3;
}

int main(){

int maxitter = 100;
double x0 = 0.0;
double xn = 0.0;
double error;

cout << "Enter intial guess: ";
cin >> x0;
cout << endl;

if(function(x0)==0.0){
  cout << "The root is: " << function(x0);
  return 0;
}

for(int i = 0; i < maxitter; i++){

xn = x0 - function(x0)/der(x0);

if(xn==x0){
cout << "The root is: " << xn << " at the " << i << " itteration";
  return 0;
}

error = abs(xn-x0);
x0 = xn;
cout << "current: " << xn << " i: " << i << endl << "---------" << endl;

}

cout << "The root is: " << xn << " at the " << maxitter << " itteration";

return 0;
}
```
**Task 2)**
```
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
```
**Task 3)**
I viewed how many iterations it took for the methods to solve the roots of f(x) = x^3 - x^2 + 2.
* Newtons method: 5 iterations
* Secant method: 10 iterations
* Bisection: 34 iterations
* Fixed point: 42 iterations
it should be noted that these methods do depend on a starting place, so I made sure to have all the starting conditions start relatively close to the root of f(x) which is -1

**Task 4)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = x^3 - x^2 + 2
// f'(x) = 3x^2 - 2x

double function(double x){
  return x*x*x - x*x + 2;
}

double der(double x){
  return 3*x*x - 2*x;
}

int biNewton(double a, double b, int maxitter){

  double x0;
  double xn;
  double k = abs(a)+abs(b);
  k = k/2;

  int i = 0;
  double eps = 0.0001;
  double c = a;

  while (abs(b-a) > eps){
      c = (a+b)/2;
      i++;
      if (function(c) == 0.0){
        cout << "Solution is " << c << " at iteration " << i;
          break;
      }

      else if (function(c)*function(a) < 0){
          b = c;
      }

      else{
        a = c;
      }
      if(abs(a-b)<k){

        x0 = a;

        if(function(x0)==0.0){
          cout << "The root is: " << x0;
          return 0;
        }

        for(int j = 0; j < maxitter; j++){

          xn = x0 - function(x0)/der(x0);

          if(xn==x0){
          cout << "The FINAL root is: " << xn << " at the " << i+j << " itteration";
            return 0;
          }

          if(abs(a-b)<abs(x0-xn)){
            cout << "The root is: " << xn << " at the " << i+j << " itteration" << endl;
            cout << "----------------" << endl;
            k = k/10;
            break;
          }

          x0 = xn;

        }

      }

   }

   return 0;

}


int main(){

biNewton(100000,-100000,100);

return 0;

}
```

- Converges in 23 iterations to -1 (correct)

**Task 5)**
```
#include <iostream>
#include <math.h>

using namespace std;

// function is f(x) = x^3 - x^2 + 2

double function(double x){
  return x*x*x - x*x + 2;
}

int biSecant(double a, double b, int maxitter){

  double x0;
  double x1;
  double xn;

  if (function(a) * function(b) >= 0){

      cout << "You have not assumed right a and b\n";
      return 0;
  }

  // k is just the middle point of a and b
  double k = abs(a)+abs(b);
  k = k/2;

  int i = 0;
  double eps = 0.0001;
  double c = a;

  while (abs(b-a) > eps){
      c = (a+b)/2;
      i++;
      if (function(c) == 0.0){
        cout << "Solution is " << c << " at iteration " << i;
          break;
      }

      else if (function(c)*function(a) < 0){
          b = c;
      }

      else{
        a = c;
      }

      if(abs(a-b)<k){

        x0=a;
        x1=b;

        if(function(x0)==0.0){
          cout << "Root is: " << x0;
          return 0;
        }

        else if(function(x1)==0.0){
          cout << "Root is: " << x1;
          return 0;
        }

        for(int j = 0; j < maxitter; j++){

          xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

          if(xn==x1){
          cout << "The FINAL root is: " << xn << " at the " << i+j << " itteration";
            return 0;
          }

          x0 = x1;
          x1 = xn;
          
          if(abs(a-b)<abs(x0-x1)){
            cout << "The root is: " << xn << " at the " << i+j << " itteration" << endl;
            cout << "----------------" << endl;
            k = k/10;
            break;
          }

        }

      }

   }

   return 0;

}


int main(){

biSecant(100000,-100000,100);

return 0;

}

```


- Converges in 25 iterations to -1 (correct)

**Task 6)**
Code placed in my [Software-manual](https://github.com/adflanders/math4610/blob/master/Software-Manual/README.md), implenting my code directly to other tasks and not using shared library as it is not working.

**Task 7)**

```
#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.1415926535897932;

double func(double x){
    return sin(pi*x*x+3.7);
}

double bisection(double a, double b){

    int i = 0;
    double eps = 0.000001;
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
    return c;
}

int main(){

    int maxiter = 1000;
    int root = 0;
    double a = 1.1, b = 68.3;
    while (a != bisection(a,b) || root < maxiter){
      if(a == bisection(a,b)){
        break;
      }
      root++;
      cout << bisection(a,b) << " is a root. #" << root << endl;
      cout << "--------------------\n";
      a = bisection(a,b);


    }

    return 0;
}
```
- output:  
1.34991 is a root. #1  
20.1946 is a root. #2  
31.0133 is a root. #3  
51.0864 is a root. #4  
67.7777 is a root. #5  
68.2336 is a root. #6  
68.2482 is a root. #7  
68.2922 is a root. #8  
68.2995 is a root. #9  
68.3 is a root. #10  

**Task 8)**

```
#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.1415926535897932;

double function(double x){
  return sin(pi*x*x+3.7);
}

double der(double x){
  return cos(pi*x*x+3.7)*2*pi*x;
}

double newton(double x0){

  int maxitter = 100;
  double xn = 0.0;
  double eps = 0.000001;


  if(function(x0)==0.0){
    return x0;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x0 - function(x0)/der(x0);

    if(abs(xn-x0) < eps){
      return xn;
    }

    x0 = xn;

  }

  return xn;

}

int main(){

  int root = 0;
  int maxiter = 1000;
  double a = 1.1;
  double b = 68.3;

  while(a <= b && root < maxiter){
    if(newton(a) < a){
      a++;
    }
    else if(newton(a) > a){
      root++;
      cout << newton(a) << " is a root. #" << root << endl;
      cout << "---------------------\n";
      a++;
    }

  }

  return 0;

}
```

- output:
2.41293 is a root. #1  
3.13405 is a root. #2  
4.10149 is a root. #3  
6.31049 is a root. #4  
7.19877 is a root. #5  
8.11309 is a root. #6  
9.10067 is a root. #7  
11.2615 is a root. #8  
12.1582 is a root. #9  
13.1081 is a root. #10  
14.1004 is a root. #11  
16.2118 is a root. #12  
17.1412 is a root. #13  
18.1059 is a root. #14  
19.1003 is a root. #15  
21.1854 is a root. #16  
22.1319 is a root. #17  
23.1046 is a root. #18  
24.1003 is a root. #19  
26.1691 is a root. #20  
27.126 is a root. #21  
28.1038 is a root. #22  
29.1002 is a root. #23  
31.158 is a root. #24  
32.122 is a root. #25  
33.1032 is a root. #26  
34.1002 is a root. #27  
36.15 is a root. #28  
37.119 is a root. #29  
38.1028 is a root. #30  
39.1002 is a root. #31  
41.1439 is a root. #32  
42.1168 is a root. #33  
43.1025 is a root. #34  
44.1001 is a root. #35  
46.1392 is a root. #36  
47.115 is a root. #37  
48.1022 is a root. #38  
49.1001 is a root. #39  
51.1353 is a root. #40  
52.1136 is a root. #41  
53.102 is a root. #42  
54.1001 is a root. #43  
56.1322 is a root. #44  
57.1124 is a root. #45  
58.1018 is a root. #46  
59.1001 is a root. #47  
61.1296 is a root. #48  
62.1114 is a root. #49  
63.1017 is a root. #50  
64.1001 is a root. #51  
66.1273 is a root. #52  
67.1105 is a root. #53  
68.1016 is a root. #54  

- Found SIGNIFICANTLY more routes with this routine.

**Task 9)**

```

#include <iostream>
#include <math.h>

using namespace std;

double function(double x){
  return 2*x*x*x + 3*x - 3;
}

double secant(double x0, double x1){

  int maxitter = 1000;
  double xn = 0.0;
  double eps = 0.00001;

  if(function(x0)<eps){
    return x0;
  }
  else if(function(x1)<eps){
    return x1;
  }

  for(int i = 0; i < maxitter; i++){

    xn = x1 - (function(x1)*(x1-x0)/(function(x1)-function(x0)));

    if(abs(xn-x1)<eps){
      return xn;
    }

    x0 = x1;
    x1 = xn;

  }

  return xn;

}

int main(){

  int root = 0;
  int maxiter = 1000;
  double a = 1.1;
  double b = 68.3;
  double tmpA;
  double tmpB;

   while(a <= b && root < maxiter){
    if(secant(a,a+1) < 1.1){
      a++;
      cout << a << endl;
    }
    else if(secant(a,a+1) > a){
      root++;
      cout << secant(a,a+1) << " is a root. #" << root << endl;
      cout << "---------------------\n";
      cout << a << endl;
      a++;
    }

  }

  return 0;

}

```

- output:
Having issue with this code. Still working on it as it is only stuck on one route and not progressing.

**Task 10)**

This published paper describes how newtons method was used in solving systems of linear equations in finding the "flow of real and reactive power in a power grid." One thing that caught my eye was the use of 3, 4, and 5 step methods. It was also reported multiple times that they did not require a jacobian matrix due to the coefficients being close. However, when applied, the accuracy increased.

source:
[http://article.sapub.org/10.5923.j.eee.20140401.01.html](http://article.sapub.org/10.5923.j.eee.20140401.01.html)
