#include <stdio.h>
#include <stdlib.h>

/*
Leonardo Rothier Soares Cardoso

sequencial

real    2m7.828s
user    2m7.628s
sys     0m0.084s


paralelizado

real    0m34.872s
user    2m17.542s
sys     0m0.096s

speedup = 3,561
*/
void mm(double* a, double* b, double* c, int width)
{
  #pragma omp parallel for
 for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      double sum = 0;
      #pragma omp simd reduction(+:sum)
      for (int k = 0; k < width; k++) {
	    double x = a[i * width + k];
	    double y = b[k * width + j];
	    sum += x * y;
      }
      c[i * width + j] = sum;
    }
  }
}

int main()
{
  int width = 2000;
  double *a = (double*) malloc (width * width * sizeof(double));
  double *b = (double*) malloc (width * width * sizeof(double));
  double *c = (double*) malloc (width * width * sizeof(double));
  #pragma omp simd collapse(2)
  for(int i = 0; i < width; i++) {
    for(int j = 0; j < width; j++) {
      a[i*width+j] = i;
      b[i*width+j] = j;
      c[i*width+j] = 0;
    }
  }

  mm(a,b,c,width);
    /*
    for(int i = 0; i < width; i++) {
      for(int j = 0; j < width; j++) {
        printf("\n c[%d][%d] = %f",i,j,c[i*width+j]);
      }
    }
    */
}
