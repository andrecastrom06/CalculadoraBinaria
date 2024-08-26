/**

 * Criado em 21 de Agosto 2024
 * Autor: André Castro
 * Questão 1 - 26/08/2024 14:09

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalbinario(int num){
  int binario[8]; 
  int cont = 0;
  if (num == 0){
    printf("Número binario de 0: 0");
  }
  else{
    printf("%d para binario: \n", num);
    while (num > 0){
      printf("%d / 2 resto é %d\n", num, num % 2);
      binario[cont] = num % 2;
      cont++;
      num /= 2;
    }
    printf("Binario: ");
    for (int kont = cont - 1; kont >= 0; kont--){
      printf("%d", binario[kont]);
    }
    printf("\n\n");
  }
}

void decimaloctal(int num){
  int octal[8]; 
  int cont = 0;
  if (num == 0){
    printf("Número em octal: 0");
  }
  else{
    printf("%d para octal: \n", num);
    while (num > 0){
      printf("%d / 8 resto é %d\n", num, num % 8);
        octal[cont] = num % 8;
        cont++;
        num /= 8;
    }
    printf("Octal: ");
    for (int kont = cont - 1; kont >= 0; kont--){
      printf("%d", octal[kont]);
    }
    printf("\n\n");
  }
}

void decimalhexa(int num) {
  char hexa[8];
  int cont = 0;
  if (num == 0) {
    printf("Número em hexadecimal: 0");
  }
  else{
    printf("%d para hexadecimal: \n", num);
    while (num > 0){
      int resto = num % 16;
      if (resto < 10){
        hexa[cont] = resto + '0';
      }
      else{
        hexa[cont] = resto + 'A' - 10;
      }
      printf("%d / 16 resto é %d; em hexadecimal: %c\n", num, resto, hexa[cont]);
        cont++;
      num /= 16;
    }
    printf("Hexadecimal: ");
    for (int kont = cont - 1; kont >= 0; kont--){
      printf("%c", hexa[kont]);
    }
  printf("\n\n");
  }
}

void decimalbcd(int num){
  int bcd[8];
  int cont = 0;
  if (num == 0) {
    printf("Número em BCD: 0000");
  }
  else{
    printf("%d para BCD: \n", num);
    while (num > 0){
      int digito = num % 10;
      num /= 10;
      printf("%d / 10 = %d\n", digito, digito);
      for (int kont = 3; kont >= 0; kont--){
        bcd[cont * 4 + kont] = (digito >> kont) & 1;
      }
      cont++;
    }
    printf("BCD: ");
    for (int kont = cont * 4 - 1; kont >= 0; kont--){
      printf("%d", bcd[kont]);
    }
    printf("\n\n");
  }
}

void decimal16bits(int num) {
  int binario[16]; 
  int cont = 15;
  for (int kont = 0; kont < 16; kont++) {
    binario[kont] = 0;
  }
  if (num < 0) {
    num = (1 << 16) + num;
  }
  while (num > 0) {
    binario[cont] = num % 2;
    num = num / 2;
    cont--;
  }
  printf("Número em binário com 16 bits: ");
  for (int kont = 0; kont < 16; kont++) {
    printf("%d", binario[kont]);
  }
  printf("\n");
}

void rfd(int num){
  
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
    else if (escolha == 2){
      printf("Qual número quer passar para octal: ");
      scanf("%d", &num);
      decimaloctal(num);
    }
    else if (escolha == 3){
      printf("Qual número quer passar para hexadecimal: ");
      scanf("%d", &num);
      decimalhexa(num);
    }
    else if (escolha == 4){
      printf("Qual número quer passar para BCD: ");
      scanf("%d", &num);
      decimalbcd(num);
    }
    else if (escolha == 5){
      printf("Qual número quer passar para binário com 16 bits e complemento a 2: ");
      scanf("%d", &num);
      decimal16bits(num);
    }
    else if (escolha == 6){
      printf("Qual número quer passar para real para float e double, mostrando bits de sinal , expoente, expoente com viés e fração: ");
      scanf("%d", &num);
      rfd(num);
    }
  }
  return 0;
}
