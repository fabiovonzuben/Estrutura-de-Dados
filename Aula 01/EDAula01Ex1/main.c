#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[5];
    int i;
    int *p;

    vetor[0]=4;
    vetor[1]=1;
    vetor[2]=22;
    vetor[3]=77;
    vetor[4]=15;

    p=vetor;
    for(i=0;i<5;i++)
    {
        printf("%d\n",*p);
        p++;
    }
    return 0;
}
