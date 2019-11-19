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
