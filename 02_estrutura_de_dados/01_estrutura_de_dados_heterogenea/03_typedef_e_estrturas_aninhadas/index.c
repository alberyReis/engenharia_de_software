#include <stdio.h>

int main(void)
{
  typedef struct
  {
    int dia;
    int mes;
    int ano;
  } Data;

  typedef struct
  {
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[2];
    int cep;
  } Endereco;

  struct ficha_aluno
  {
    int matricula;
    char nome[50];
    char disciplina[50];
    float nota;

    Data datanasc;
    Endereco endaluno;
  };

  struct ficha_aluno aluno[2];

  int i;

  printf("\n********** Ficha do Aluno **********\n");

  for (i = 0; i < 2; i++)
  {
    printf("Matricula: ");
    scanf("%d", &aluno[i].matricula);

    printf("Nome: ");
    scanf("%s", &aluno[i].nome);

    printf("Rua: ");
    scanf("%s", &aluno[i].endaluno.rua);

    printf("Numero: ");
    scanf("%d", &aluno[i].endaluno.numero);

    printf("Bairro: ");
    scanf("%s", &aluno[i].endaluno.bairro);

    printf("Cidade: ");
    scanf("%s", &aluno[i].endaluno.cidade);

    printf("Estado: ");
    scanf("%s", &aluno[i].endaluno.estado);

    printf("CEP: ");
    scanf("%d", &aluno[i].endaluno.cep);

    printf("Dia do nascimento: ");
    scanf("%d", &aluno[i].datanasc.dia);

    printf("Mes do nascimento: ");
    scanf("%d", &aluno[i].datanasc.mes);

    printf("Ano do nascimento: ");
    scanf("%d", &aluno[i].datanasc.ano);

    printf("Disciplina: ");
    scanf("%s", &aluno[i].disciplina);

    printf("Nota: ");
    scanf("%f", &aluno[i].nota);
  };

  for (i = 0; i < 2; i++)
  {
    printf("\n********** Ficha do Aluno **********\n");
    printf("Matricula: %d\n", aluno[i].matricula);
    printf("Nome: %s\n", aluno[i].nome);
    printf("Endereco: Rua %s %d, Bairro %s, Cidade %s-%s, CEP: %d\n", aluno[i].endaluno.rua, aluno[i].endaluno.numero, aluno[i].endaluno.bairro, aluno[i].endaluno.cidade, aluno[i].endaluno.estado, aluno[i].endaluno.cep);
    printf("Data de nascimento: %d/%d/%d\n", aluno[i].datanasc.dia, aluno[i].datanasc.mes, aluno[i].datanasc.ano);
    printf("Nota: %.2f\n\n", aluno[i].nota);
  };
  system("pause");
  return (0);
};