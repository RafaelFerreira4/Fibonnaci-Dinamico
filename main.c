#include <stdio.h>

long long int fibonacciSimples(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacciSimples(n - 1) + fibonacciSimples(n - 2);
}

unsigned long long int fibonacciDinamico(int n, unsigned long long int *resultadosEncontrados)
{
    //Verifica se o resultado daquele fib(n) ja foi calculado
    if (resultadosEncontrados[n - 1] != -1)
        return resultadosEncontrados[n - 1];
    else //Caso nao tenha sido calculado, realiza o calculo e armazena o resultado
    {
        resultadosEncontrados[n - 1] = fibonacciDinamico(n - 1, resultadosEncontrados) + fibonacciDinamico(n - 2, resultadosEncontrados);
        return resultadosEncontrados[n - 1];
    }
}

int main()
{
    int elementoFib;
    printf("Insira qual elemento de Fibonnaci deseja calcular: ");
    scanf("%d", &elementoFib);
    unsigned long long int *resultados;
    //Alocacao dinamica do vetor para armazenar todos os valores calculados
    resultados = (unsigned long long int *)calloc(elementoFib, sizeof(unsigned long long int));
    //Preenchendo o vetor com -1 para sabermos quais valores não foram calculados ainda
    for (int i = 0; i < elementoFib; i++)
        resultados[i] = -1;

    //Primeiros valores da sequencia
    resultados[0] = 0;
    resultados[1] = 1;

    unsigned long long int resposta = fibonacciDinamico(elementoFib, resultados);
    printf("O %d Elemento da sequencia de Fibonacci eh %llu.", elementoFib, resposta);
    free(resultados);

    return 0;
}
