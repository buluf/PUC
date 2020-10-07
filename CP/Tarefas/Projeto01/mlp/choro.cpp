#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>


int main()
{

    FILE *pFile;
    pFile = fopen("entrada.txt", "w");

    FILE *fileSaida;
    fileSaida = fopen("saida.txt","w");

    int numeros[2][1000];

    srand(time(NULL));

    

    for (int i = 1; i <= 1000; i ++)
    {
        numeros[0][i] = rand()%1000;
        numeros[1][i] = rand()%1000;;
    }



    for (int i = 1; i <= 1000; i ++)
    {
        int sum = numeros[0][i] +  numeros[1][i];
        fprintf(pFile,"%d %d\n",numeros[0][i],numeros[1][i]);
        fprintf(fileSaida,"%d\n",sum);
    }

    

    fclose(pFile);

    return 0;
}