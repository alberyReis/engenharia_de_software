#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

#define TAMANHO_PILHA 65536

typedef struct 
{
    char nome[50];
    double saldo;
} Registro;

Registro registro[500];

void cria_conta(char *nome, int numero, float saldo) 
{
    strcpy(registro[numero].nome, nome);
    registro[numero].saldo = saldo;
}

void mostra_conta(int numero) 
{
    printf("A conta de %s possui R$%.2f.\n", registro[numero].nome, registro[numero].saldo);
}

Registro le_registro(int conta) 
{
    return registro[conta];
}

void grava_registro(Registro reg, int conta) 
{
    registro[conta] = reg;
}

void atualiza_saldo(double valor, int conta) 
{
    Registro reg;
    reg = le_registro(conta);
    printf("Iniciando operação [%.2f] (saldo atual = R$%.2f).\n", valor, reg.saldo);
    usleep(1000);
    reg.saldo = reg.saldo + valor;
    grava_registro(reg, conta);
    printf("Terminada operação [%.2f] (saldo atual = R$%.2f).\n", valor, reg.saldo);
}

int funcaoDeposito(void *arg) 
{
    atualiza_saldo(100, 231);
}

int funcaoSaque(void *arg) 
{
    atualiza_saldo(-200, 231);
}

int main() 
{
    void *pilha1, *pilha2;
    int pid1, pid2;

    cria_conta("Jose Maria", 231, 500);
    printf("Saldo antes das operações: ");
    mostra_conta(231);

    if((pilha1 = malloc(TAMANHO_PILHA)) == 0) {
        perror("Erro na alocação da pilha");
        exit(1);
    }

    if((pilha2 = malloc(TAMANHO_PILHA)) == 0) {
        perror("Erro na alocação da pilha");
        exit(1);
    }

    pid1 = clone(funcaoDeposito, pilha1 + TAMANHO_PILHA, CLONE_VM|SIGCHLD, NULL);
    pid2 = clone(funcaoSaque, pilha2 + TAMANHO_PILHA, CLONE_VM|SIGCHLD, NULL);

    waitpid(pid1, 0, 0);
    waitpid(pid2, 0, 0);
}
