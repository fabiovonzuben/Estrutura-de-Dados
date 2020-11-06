#include <stdio.h>
#include <stdlib.h>

int soma (int x);

int main()
{

    int s;
    int n = 5;

    s = soma(n);

    printf("Soma: 1 a %d igual a %d", n, s);

    return 0;
}

    int soma (int x){
        if(x == 1){
            return 1;
        }
        else{
            return x + soma(x-1);
        }
    }
