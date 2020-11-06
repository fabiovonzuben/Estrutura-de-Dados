#include <stdio.h>
#include <stdlib.h>

int soma(int valor);

int main()
{
    int n;
    int s;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    s = soma(n);

    printf("A soma de 1 a %d eh %d", n, s);
    return 0;
}

int soma(int valor)
{
    if(valor == 1)
        return 1;
    else
        return valor * soma(valor - 1);
}
