# Tasks predicated off of the list given [here](https://jvkoebbe.github.io/math4610/tasksheets/html/tasksheet_04.html)

* Notes for Dr. Koebbe:

**Task 1)**

I would say that using just newtons method or secant method would be better than using a hybrid method FOR a function like sin(x) or cos(x) since
we know that the multiple roots won't be that far away from eachother. I would apply a hybrid method to a function where the roots could
be far apart, but not such with a trig function. Secondly, based on my own results, newtons method worked far better in finding many more roots
than bisection did.

**Task 2)**

All the norm routines were added to my [software-manual page](https://github.com/adflanders/math4610/tree/master/Software-Manual) under the vector routine section.

- 1-norm

```
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void norm1(vector<double> &k){

  double sum = 0.0;
  for(int i = 0; i < k.size(); i++){
    sum = sum + k[i];
  }
  cout << sum;

}

int main(){

  vector<double> k;
  k.push_back(12.3);
  k.push_back(7.1);

  norm1(k);

  return 0;

}
```

- 2-norm

```
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void norm2(vector<double> &k){

  double sum = 0.0;
  for(int i = 0; i < k.size(); i++){
    sum = sum + k[i]*k[i];
  }
  cout << sqrt(sum);

}

int main(){

  vector<double> k;
  k.push_back(3);
  k.push_back(4.2);

  norm2(k);

  return 0;

}
```

- inf-norm

```
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void infNorm(vector<double> &k){

  double tmp = 0.0;
  for(int i = 0; i < k.size(); i++){
    if(tmp < k[i]){
      tmp = k[i];
    }
  }
  cout << tmp;

}

int main(){

  vector<double> k;
  k.push_back(3);
  k.push_back(4.2);
  k.push_back(19.3);
  k.push_back(7.7);

  infNorm(k);

  return 0;

}
```


**Task 3)**

- Showing the 1-norm with relative error computed. Will link the norms with their respective error types. [1-norm](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/1normerr.md), [2-norm](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/2normerr.md), [inf-norm](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/infnormerr.md)

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double errrel(double j, double k){

double m = abs(j - k);
double t = m/j;

return t;
}

int main(){

  //actual generated vector
  vector<double> k;
  //rounded off 'estimated' vector
  vector<double> t;

  srand(unsigned(time(NULL)));

  //creates random vector WITH decimals, then makes one rounded off i.e 'estimated'.

  for(int i = 0; i < 8; i++){

    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

    t.push_back(round(k[i]));

  }

  double sumK = 0.0;
  double sumT = 0.0;

  for(int i = 0; i < k.size(); i++){
    sumK = sumK + k[i];
  }
  cout << "Actual norm1: " << sumK << endl;

  for(int i = 0; i < t.size(); i++){
    sumT = sumT + t[i];
  }
  cout << "Estimated norm1: " << sumT << endl;

  cout << errrel(sumK, sumT) << " is the relative error.";

  return 0;
}

```

- output:  
Actual norm1: 49.2461  
Estimated norm1: 50  
0.0153093 is the relative error.

**Task 4)**

- Sum

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(){

  vector<double> k;
  vector<double> t;
  srand(unsigned(time(NULL)));

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){
    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
    t.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  vector<double> sum;

  for(int i = 0; i < k.size(); i++){
    sum.push_back(k[i]+t[i]);
  }

  cout << "Sum of vectors k and i:\n" << "-----------------\n";

  for(int i = 0; i < sum.size(); i++){
    cout << sum[i] << endl;
  }


  return 0;
}

```

- output:  
Sum of vectors k and i:    
8.83066  
6.11408  
8.5765  
15.9009  
9.53993  
10.7704  
14.5185  
7.28756  


- Difference

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;


int main(){

  vector<double> k;
  vector<double> t;
  srand(unsigned(time(NULL)));

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){
    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
    t.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  vector<double> dif;

  for(int i = 0; i < k.size(); i++){
    dif.push_back(abs(k[i]-t[i]));
  }

  cout << "Absolute difference of vectors k and i:\n" << "-----------------\n";

  for(int i = 0; i < dif.size(); i++){
    cout << dif[i] << endl;
  }

  return 0;
}
```

- output:  
Difference of vectors k and i:    
6.38878  
3.17877  
-0.102848  
-2.15041  
-5.28654  
-7.78679  
-0.941228  
6.80897  



- Scalar

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;


int main(){

  vector<double> k;
  vector<double> t;
  srand(unsigned(time(NULL)));

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){
    k.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));
  }

  double scal = (double)rand()/(RAND_MAX + 1.0)+1+(rand()%5);

  for(int i = 0; i < k.size(); i++){
    k[i] = k[i]*scal;
  }

  cout << "Scalar multiple of vector k:\n" << "-----------------\n";
  cout << "Scalar: " << scal << endl;

  for(int i = 0; i < k.size(); i++){
    cout << k[i] << endl;
  }

  return 0;
}

```

- output:  
Scalar multiple of vector k:    
Scalar: 2.60551  
17.5098  
12.0998  
15.1804  
4.42562  
22.5502  
16.1368  
26.4721  
25.3662  

**Task 5)**

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
  srand(unsigned(time(NULL)));

  //setting up y = mx + b. y,x,b are vectors, m is a scalar

  //vector x
  vector<double> x;
  //vector b
  vector<double> b;
  //vector y
  vector<double> y;
  //scalar m
  double m = rand()%5;

  //creates 2 random vectors.

  for(int i = 0; i < 8; i++){

    x.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

    b.push_back((double)rand()/(RAND_MAX + 1.0)+1+(rand()%10));

  }

  for(int i = 0; i < x.size(); i++){
    y.push_back(m*x[i] + b[i]);
    cout << "y[" << i << "] = " << y[i] << endl;
  }

  return 0;
}

```

- output:
```
y[0] = 9.64994  
y[1] = 7.30255  
y[2] = 8.01002  
y[3] = 1.83698  
y[4] = 7.55513  
y[5] = 1.33056  
y[6] = 8.69084  
y[7] = 2.57126  
```

- [Software page for SAXPY](https://github.com/adflanders/math4610/blob/master/Software-Manual/pages/saxp.md)


**Task 6)**

- Both Dot and Cross product added to [Software-Manual](https://github.com/adflanders/math4610/blob/master/Software-Manual)

- Dot Product:

```
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
```

- output:  
x[0] = 6.81261   |   b[0] = 8.25306  
x[1] = 10.0851   |   b[1] = 5.85726  
x[2] = 1.70383   |   b[2] = 5.75139  
The dot product is: 125.095  

- Cross Product:

```
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
```

- output:  
x[0] = 5.63351   |   b[0] = 2.8244  
x[1] = 2.24448   |   b[1] = 8.64998  
x[2] = 6.4774    |   b[2] = 6.23655  

The cross product is:  

y[0] = -42.0315  
y[1] = -16.8389  
y[2] = 42.3905  

**Task 7)**

```
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

```

- output:  
  
A =  
10.2437  5.21825  10.311  
10.9988  10.5819  2.14225  
3.75554  6.73713  8.6418  
  
x =  
6.65906  
8.25951  
4.44356  
  
y =  
157.131  
170.163  
119.054  


**Task 8)**

```
#include <omp.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

    #pragma omp parallel
    {
      printf("Hello World... from thread = %d\n", omp_get_thread_num());
    }

    cout << "Total number of processors: " << omp_get_num_procs();
}

```

- output:  
Hello World... from thread = 1  
Hello World... from thread = 6  
Hello World... from thread = 7  
Hello World... from thread = 2  
Hello World... from thread = 3  
Hello World... from thread = 4  
Hello World... from thread = 0  
Hello World... from thread = 5  
Total number of processors: 8


**Task 9)**

```
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

// #pragma omp parallel for
for(int i = 0; i < 3; i++)
{
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
  #pragma omp parallel for
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++){
      y[i] = x[j]*a[i][j] + y[i];
    }
    cout << y[i] << endl;
}
  return 0;
}

```
