#define _GNU_SOURCE
#define TAMANHO_PILHA 65536
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

int contador;

static int funcao_a(void *arg)
{
    while (1)
    {
        printf("Para a função A contador = %d.\n", contador);
        usleep(3000000);
    }
}

static int funcao_b(void *arg)
{
    while (1)
    {
        printf("Função B incrementando contador.\n");
        contador = contador + 1;
        printf("Para a função B contador = %d.\n", contador);
        usleep(3000000);
    }
}

void main(void)
{
    void *pilha_a, *pilha_b;
    int i, pid_a, pid_b, id_a, id_b;

    if ((pilha_a = malloc(TAMANHO_PILHA)) == 0)
    {
        perror("Erro na alocação da pilha da função A.");
        exit(1);
    }

    if ((pilha_b = malloc(TAMANHO_PILHA)) == 0)
    {
        perror("Erro na alocação da pilha para a função B.");
        exit(1);
    }

    contador = 0;

    pid_a = clone(funcao_a, pilha_a + TAMANHO_PILHA, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD, &id_a);
    pid_b = clone(funcao_b, pilha_b + TAMANHO_PILHA, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD, &id_b);
    waitpid(pid_a, 0, 0);
    waitpid(pid_b, 0, 0);
}