#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalbinario(int num){
  int binario[8]; 
  int cont = 0;
  if (num < 0) {
    num = (1 << 7) + num;
  }
  while (num > 0) {
    binario[cont] = num % 2; 
    num = num / 2;     
    cont++;
  }
  printf("Número em binário: ");
  for (int kont = cont - 1; kont >= 0; kont--) {
    printf("%d", binario[kont]);
  }
  printf("\n");
}

void decimaloctal(int num){
  int binario[8]; 
  int cont = 0;
  if (num == 0){
    printf("Número em Octal: 0\n");
    return;
  }
  if (num < 0) {
    while (num != 0) {
      binario[cont] = - (num % 8); 
      num = num / 8;     
      cont++;
    }
    printf("Número em Octal: -");
    for (int kont = cont - 1; kont >= 0; kont--) {
      printf("%d", binario[kont]);
    }
    printf("\n");
    return;
  }
  while (num > 0) {
    binario[cont] = num % 8; 
    num = num / 8;     
    cont++;
  }
  printf("Número em Octal: ");
  for (int kont = cont - 1; kont >= 0; kont--) {
    printf("%d", binario[kont]);
  }
  printf("\n");
}

int main(void) {
  int escolha = 0, num;
  while(escolha != 7){ 
    printf("1 - Decimal para binário\n2 - Decimal para octal\n3 - Decimal para hexadecimal\n4 - Decimal para BCD\n5 - Decimal para binário com sinal com 16 bits usando complemento a 2\n6 - Real para float e double, mostrando bits de sinal , expoente, expoente com viés e fração\n7 - Sair\n-> ");
    scanf("%d", &escolha);
    if (escolha == 1){
      printf("Qual número quer passar para binário: ");
      scanf("%d", &num);
      decimalbinario(num);
    }
    if (escolha == 2){
      printf("Qual número quer passar para octal: ");
      scanf("%d", &num);
      decimaloctal(num);
    }
  }
  return 0;
}
