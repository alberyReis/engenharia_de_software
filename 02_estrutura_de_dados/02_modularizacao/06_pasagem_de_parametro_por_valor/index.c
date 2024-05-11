#include <stdio.h>
#include <stdlib.h>

int soma(int x, int y) {
  return(x + y);
}

int main() 
{
  int num1, num2, total;

  printf("Digite um numero: ");
  scanf("%d", &num1);

  printf("Agora digite outro numero: ");
  scanf("%d", &num2);

  total = soma(num1, num2);
  printf("A soma de %d e %d = %d\n", num1, num2, total);

  system("pause");
  return(0);
}