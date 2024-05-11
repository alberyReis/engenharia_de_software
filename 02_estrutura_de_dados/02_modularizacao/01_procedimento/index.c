#include <stdio.h>
#include <conio.h>

float pmedia()
{
  float n1 = 0, n2 = 0, m = 0;

  printf("Digite primeira nota do aluno: ");
  scanf("%f", &n1);
  printf("Digite a segunda nota do aluno: ");
  scanf("%f", &n2);

  m = (n1 + n2) / 2;
  printf("\n\nA media do aluno foi %6.2f", m);
};

main() 
{
  pmedia();
  getch();
};