#include <stdio.h>
#include <unistd.h>

void main(int argc, char **argv, char* envp[]) 
{
    int pid;

    pid = fork();
    if(pid != 0)
    {
        printf("Processo pai em execução (PID: %d). PID do filho = %d\n", getpid(), pid);
    }
    else
    {
        printf("Carregando código do processo filho.\n");
        execve("proc_filho", argv, envp);
    }
}