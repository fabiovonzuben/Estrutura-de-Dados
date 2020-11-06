#include <stdio.h>

void adicionar(int valor);
int quantidadeElementos();
int buscarPorIndice(int indice);
int buscarPorValor(int valor);
void excluir(int valor);
void ordenar();
void expandir();
void inicializar();
void finalizar();
void listar();

void menu();

int tamanho = 5;
int posicao = 0;
int *lista;
int opcao;
int numero;
int indice;

int main()
{
    inicializar();
    opcao = 0;
    while(opcao !=8)
    {
        menu();
        switch(opcao)
        {
        case 1:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            adicionar(numero);
            break;
        case 2:
            printf("A lista possui %d elementos.\n", quantidadeElementos());
            break;
        case 3:
            printf("Digite o indice: ");
            scanf("%d", &indice);

            numero = buscarPorIndice(indice);
            if(numero == -1)
                printf("Indice invalido!\n");
            else
                printf("Valor encontrado no indice %d = %d\n", indice, numero);
            break;
        case 4:
            printf("Digite o numero: ");
            scanf("%d", &numero);

            indice = buscarPorValor(numero);
            if(indice == -1)
                printf("Nao encontrei %d na lista!\n", numero);
            else
                printf("Encontreio valor %d no indice %d\n", numero, indice);
            break;
        case 5:
            printf("Digite o valor para excluir: ");
            scanf("%d", &numero);
            excluir(numero);
            break;
        case 6:
            printf("Ordenando...\n");
            ordenar();
            break;
        case 7:
            listar();
            break;
        }
    }
    finalizar();
}

void inicializar()
{
    lista = malloc(tamanho * sizeof(int));
    if(!lista)
    {
        printf("Erro de alocacao!");
        exit(-1);
    }
}

void finalizar()
{
    free(lista);
}

void menu()
{
    printf("1 - Adicionar\n");
    printf("2 - Quantidade de Elementos\n");
    printf("3 - Buscar por Indice\n");
    printf("4 - Buscar por Valor\n");
    printf("5 - Excluir\n");
    printf("6 - Ordenar\n");
    printf("7 - Listar\n");
    printf("8 - Sair\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &opcao);
}

void listar()
{
    int i;
    for(i = 0; i < posicao; i++)
        printf("lista[%d] = %d\n", i, lista[i]);
}

void adicionar(int valor)
{
    if(posicao < tamanho)
    {
        lista[posicao] = valor;
        posicao++;
    }
    else
    {
        expandir();
        adicionar(valor);
    }
}

int quantidadeElementos()
{
    return posicao;
}

int buscarPorIndice(int indice)
{
    if(indice >= 0 && indice < posicao)
        return lista[indice];
    else
        return -1;
}

int buscarPorValor(int valor)
{
    int i = 0;
    for(i = 0; i < posicao; i++)
        if(lista[i] == valor)
            return i;
    return -1;
}

void excluir(int valor)
{
    int i = 0;
    i = buscarPorValor(valor);
    if(i != -1)
    {
        for(; i < posicao - 1; i++)
            lista[i] = lista[i + 1];
        posicao--;
    }
    else
        printf("Nao encontrei %d na lista!\n", valor);
}

void ordenar()
{
    int i = 0;
    int j = 0;
    int aux = 0;

    for(i = 0; i < (posicao -1); i++)
    {
        for(j = i + 1; j < posicao; j++)
        {
            if(lista[i] > lista[j])
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void expandir()
{
    printf("Expandindo o array...\n");
    int novoTamanho = tamanho + (tamanho / 2);
    int *p;
    int i;

    p = malloc(novoTamanho * sizeof(int));
    if(!p)
    {
        printf("Erro na alocacao de memoria!");
        exit(-1);
    }

    for(i = 0; i < tamanho; i++)
        p[i] = lista[i];

    free(lista);
    lista = p;
    tamanho = novoTamanho;
}
