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
-----------------  
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
-----------------  
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
-----------------  
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
