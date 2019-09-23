# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_01.html)

* Notes for Dr. Koebbe: The shared library is still a work in progress and I am trying to resolve the problems. That said, all the cpp files that hold the actual functions are located [here](https://github.com/adflanders/math4610/tree/master/src) if you wish to grade/look at them for confirmation.

Task 1) Emailed you my [github page](https://adflanders.github.io/).

Task 2) Emailed you regarding my math4610 repo and that it is indeed private and sent you an invite.

Task 3) Emailed you letting you know that I will be using cygwin.

[Task 4)](https://github.com/adflanders/math4610/blob/master/hw_toc/task_sheet_1/whatLang.cpp) Show which coding language we plan on using via a program.

```cpp
#include <iostream>

using namespace std;

int main(){

cout << "I will be using c++ for this course." << endl;


return 0;
}
```

Task 5) Emailed you my math4610 repo's table of contents for homework.

[Task 6)](https://github.com/adflanders/math4610/blob/master/hw_toc/task_sheet_1/centDer.cpp) Use the central difference form for computing a derivative to show how machince precision collapses as h -> (infinity). 

```cpp
//for the fuction f(x) =  e^(x)

#include <iostream>
#include <math.h>

using namespace std;

double compErr(float x, float h){

    double function = (exp(x+h)-exp(x-h))/((x+h)-(x-h));

  return function;
}


int main(){

    //stating what the function is, its derivative, and its value at a given point
    cout << endl << "f(x) = e^(x)" << endl;
    cout << "f'(x) = e^(x) => f'(1) = e = " << exp(1) << endl << endl;
    
    double y = 1.0;
    double k;
    k = 1.0;
    int iter = 1;
    
    while(exp(1.0) != compErr(y,k) && iter <= 60){

      cout << "Iteration: " << iter << endl;
      cout << compErr(y,k) << endl;
      cout << "-------------------" << endl;
      k = k * 0.75;
      iter++;

    }


return 0;
}
```


[Task 7)](https://github.com/adflanders/math4610/tree/master/src) Created the abs and rel error functions and put them in my src folder.

abs error:
```cpp
#include <iostream>
#include <math.h>

using namespace std;

// function that computes absolute error

double errabs(double j, double k){

      double m = abs(j - k);

  return m;
}
```
rel error:

```cpp
#include <iostream>
#include <math.h>

using namespace std;

//function that computes Relative error. raw value, not percentage

double errrel(double j, double k){

double m = abs(j - k);
double t = m/j;

return t;
}
```

[Task 8)](https://github.com/adflanders/math4610/tree/master/srcLibrary) Created my shared library and also implemented my smaceps and dmaceps functions in it. (Still working on/figuring out shared library for c++).

smaceps:
```cpp
#include <iostream>

using namespace std;

int main(){

  double one = 1.0;
  double eps = 1.0;
  double diff;

  for(int i=0;i<1000;i++){

    diff = one - (one + eps);
    cout << "Difference: " << diff << endl << "Epsilon: " << eps << endl;
    cout << "--------------------------" << endl << endl;
    if(diff==0){
      cout << "final epsilon: " << eps << endl << "final iteration: " << i;
      return 0;
    }

    eps *= 0.5;

  }

  return 0;
}
```

dmaceps:
```cpp
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
```

[Task 9)](https://github.com/adflanders/math4610/blob/master/hw_toc/task_sheet_1/piExp.cpp) Use the central difference form for computing the derivative of f(x)=e^(x) and then evaluate f'(x) at f'(pi). Use the absolute and relative error routines from [adamslib.a](https://github.com/adflanders/math4610/blob/master/srcLibrary/adamslib.a).

```cpp
//for the fuction f(x) =  e^(pi)
#include "src.h"
#include <iostream>
#include <math.h>

using namespace std;

const double pi = 3.14159265358979323846264338327950288419716;

double compErr(float x, float h){

    double function = (exp(x+h)-exp(x-h))/((x+h)-(x-h));

  return function;
}


int main(){

    cout << endl << "f(x) = e^(x)" << endl;
    cout << "f'(x) = e^(x) => f'(1) = e = " << exp(pi) << endl << endl;
    double y = pi;
    double k;
    k = 1.0;
    int iter = 1;
    while(exp(pi) != compErr(y,k) && iter <= 60){

      cout << "Iteration: " << iter << endl;
      cout << compErr(y,k) << endl;
      cout << "-------------------" << endl;
      k = k * 0.75;
      iter++;

    }

    // for k = 21 (21st Iteration) is closely approximated to exp(pi)

    k = pow(0.75,21);
    
    errabs(compErr(y,k),exp(pi));
    errrel(compErr(y,k),exp(pi));
    smaceps();


return 0;
}
```

[Task 10)](https://github.com/adflanders/math4610/blob/master/hw_toc/task_sheet_1/abs&rel.md) Write about our findings online regarding what absolute and relavtive error is along with how they are used.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The site helped bring about more analogies regarding when and how to employ absolute over relativer error or vice versa.
explicitly, it defines them in such ways that completely encapsulates their purpuse. For Absolute error, it simply just states how far off the real and approxomite numbers are from eachother. While Relative error is how large the real number is compared to the approximate one.


site used:

[Absolute and Relative Error Calculation](https://www.thoughtco.com/absolute-and-relative-error-calculation-609602)
