#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char letra;

  printf("Digite uma letra: ");
  scanf("%c", &letra);
  printf("A letra digitada foi %c\n", letra);

  return(0);
}