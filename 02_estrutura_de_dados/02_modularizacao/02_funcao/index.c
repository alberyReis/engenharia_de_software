#include <stdio.h>
#include <conio.h>

float fmedia(float n1, float n2)
{
  float m = 0;
  m = (n1 + n2) / 2;
  return m;
}

main() {
  float num1 = 0, num2 = 0;

  printf("Digite primeira nota do aluno: ");
  scanf("%f", &num1);
  printf("Digite a segunda nota do aluno: ");
  scanf("%f", &num2);
  printf("\n\nA media do aluno foi %6.2f", fmedia(num1, num2));

  getch();
}