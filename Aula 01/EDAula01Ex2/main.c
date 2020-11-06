#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ponto
    {
        float latitude;
        float longitude;
    };

    struct ponto fatec;
    fatec.latitude = -22.423010;
    fatec.longitude = -46.949501;

    printf("A fatec fica em: (%f, %f)", fatec.latitude, fatec.longitude);
    return 0;
}
