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
