#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    // 1
	
	//devec.c:4:5: note: not vectorized: not enough data-refs in basic block.
    //Número de interações baixa
    /*
        int a [4] = {1,2,3,4};
        int b [4] = {1,2,3,4};
        int c [4] = {1,2,3,4};
        for (int i = 0; i <sizeof(a)/sizeof(a[0]); i++)
        {
                a [i] = b[i] + c[i];
        }
    */

	
	//2

	//	O programa possui um break.
	// devec.c:26:3: note: not vectorized: loop contains function calls or data references that cannot be analyzed
    /*
		int n = 1000000000;
		int a[1000000000];
		int b[1000000000];
		int c[1000000000];
		for (int i = 0; i < n;i++)
		{
			a[i] = rand()%1000;
			b[i] = rand()%1000;
			c[i] = rand()%1000;
		}
		for (int j = 0; j < n; j++)
		{
			a [j] = b[j] + c[j];
			if (a[j] == 100000000){
				break;
			}
			
		}
    */

	/*
		3-
			Dependência na variável result.
			devec.c:47:3: note: not vectorized: loop contains function calls or data references that cannot be analyzed
            devec.c:47:3: note: bad data references.
    */

    /*
		int n = 1000000000;
		int a[n];
		int b[n];
        int result = 0;
		for (int i = 0; i < n;i++)
		{
			a[i] = rand()%1000;
			b[i] = rand()%1000;
		}
		for (int j = 1; j < n; j++)
		{
			result = result + a[j] * b[j];
		}
	*/

	/*
		4-
			// diferentes fluxo de controle pelo if aleatoriamente ficar alternando
			// entre ele e o else.
			devec.c:83:3: missed: not vectorized: control flow in loop.
    */
  
		int n = 1000000000;
		int a[n];
		int b[n];
		for (int i=0; i< n; i++) {
			a[i] = rand()%1000;
			b[i] = rand()%1000;
		}
		for (int j = 1; j < n; j++)
		{
			float random = b[j]*b[j] - 2*a[j]*b[j]; 
			if(random >= 0){
			random = sqrt(random);
				a[j-1] = a[j] +1*random;
				b[j] = a[j] * 2/random;
			}
			else{
				a[j] = 0;
				b[j] = 0;
			}
		}
    

	/*
		5-
			Conversão de tipos.
			 note: not vectorized: not enough data-refs in basic block.
    */
   /*
		long long num = 1000000000;
		double passo;
		passo = 1.0/(double)num;
	*/
	return 0;
}