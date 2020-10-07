/*
Sequencial:

real    0m16.953s
user    0m16.885s
sys     0m0.012s

Parallel:
real    0m3.471s
user    0m6.353s
sys     0m0.020s

Parallel_Schedule:

real    0m3.266s
user    0m6.372s
sys     0m0.096s

speedup(média de 5 execuções):4.676/3.338 = 1,4008

*/
#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int i, j, n = 80000; 

   // Allocate input, output and position arrays
   int *in = (int*) calloc(n, sizeof(int));
   int *pos = (int*) calloc(n, sizeof(int));   
   int *out = (int*) calloc(n, sizeof(int));   

   // Initialize input array in the reverse order
   for(i=0; i < n; i++)
      in[i] = n-i;  

   // Print input array
   //   for(i=0; i < n; i++) 
   //      printf("%d ",in[i]);
    
   // Silly sort (you have to make this code parallel)
   #pragma omp parallel for private(i,j) schedule(dynamic, 100) num_threads(2)
   for(i=0; i < n; i++) 
      for(j=0; j < n; j++)
	     if(in[i] > in[j]) 
            pos[i]++;	

   // Move elements to final position
   for(i=0; i < n; i++) 
      out[pos[i]] = in[i];
   
   // print output array
   //   for(i=0; i < n; i++) 
   //      printf("%d ",out[i]);

   // Check if answer is correct
   for(i=0; i < n; i++)
      if(i+1 != out[i]) 
      {
         printf("test failed\n");
         exit(0);
      }

   printf("test passed\n"); 
}  
