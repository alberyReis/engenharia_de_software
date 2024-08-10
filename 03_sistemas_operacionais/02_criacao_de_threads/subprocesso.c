#include <stdio.h>
#include <unistd.h>

int contador;

void funcao_a(void) 
{
    while(1)
    {
        printf("Para a função A contador = %d.\n", contador);
        usleep(3000000);
    }
}

void funcao_b(void) 
{
    while(1) 
    {
        printf("Função B incrementando contador.\n");
        contador = contador + 1;
        printf("Para a função B contador = %d.\n", contador);
        usleep(3000000);
    }
}

void main(void)
{
    int pid;

    contador = 0;
    pid = fork();

    if(pid == 0) 
    {
        funcao_a();
    }
    else
    {
        funcao_b();
    }
}