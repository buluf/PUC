/*
* Adapted from: http://w...content-available-to-author-only...s.org/sieve-of-eratosthenes

Leonardo Rothier Soares Cardoso

Sequencial(parcode)
real    0m4.050s
user    0m3.965s
sys     0m0.068s

Parallel(parcode)
real    0m2.547s
user    0m9.772s
sys     0m0.064s

Parallel_Com_Escalonamento(parcode)

real    0m2.265s
user    0m8.695s
sys     0m0.076s

speedup(média de 4 execuções): 4,042/2,321 = 1,7414
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int sieveOfEratosthenes(int n)
{
   // Create a boolean array "prime[0..n]" and initialize
   // all entries it as true. A value in prime[i] will
   // finally be false if i is Not a prime, else true.
   int primes = 0; 
   bool *prime = (bool*) malloc((n+1)*sizeof(bool));
   int sqrt_n = sqrt(n);

   memset(prime, true,(n+1)*sizeof(bool));
   #pragma omp parallel for schedule (dynamic)
   for (int p=2; p <= sqrt_n; p++)
   {
       // If prime[p] is not changed, then it is a prime
       if (prime[p] == true)
       {
           // Update all multiples of p
           #pragma omp parallel for
           for (int i=p*2; i<=n; i += p)
           prime[i] = false;
        }
    }

    // count prime numbers
    #pragma omp parallel for reduction(+:primes) schedule (dynamic, 500)
    for (int p=2; p<=n; p++)
       if (prime[p])
         primes++;

    return(primes);
}

int main()
{
   int n = 100000000;
   printf("%d\n",sieveOfEratosthenes(n));
   return 0;
} 