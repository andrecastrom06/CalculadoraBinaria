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

void decimalhexa(int num) {
  char hexadecimal[8];
  int cont = 0;
  if (num == 0) {
    printf("Número em Hexadecimal: 0\n");
    return;
  }
  unsigned int numhexa;
  if (num < 0) {
      numhexa = (unsigned int)num;
  } 
  else {
      numhexa = num;
  }
  while (numhexa > 0) {
    int resto = numhexa % 16;
    if (resto < 10) {
      hexadecimal[cont] = resto + '0'; 
    } 
    else {
      hexadecimal[cont] = resto - 10 + 'A';
    }
      numhexa /= 16;
    cont++;
  }
  if (num < 0) {
    printf("Número em Hexadecimal: -");
  } 
  else {
    printf("Número em Hexadecimal: ");
  }
  for (int kont = cont - 1; kont >= 0; kont--) {
    printf("%c", hexadecimal[kont]);
  }
  printf("\n");
}

void decimalbcd(int num){
  int bcd[8 * 4];
  int algarismos[8];
  int cont = 0;
  int kont = 0;
  if (num == 0) {
    printf("Número em BCD: 0000\n");
    return;
  }
  while (num != 0) {
    algarismos[kont] = num % 10;
    num = num / 10;
    kont++;
  }
  for (int conti = kont - 1; conti >= 0; conti--) {
    int konti = algarismos[conti];
    for (int conte = 3; conte >= 0; conte--) {
      bcd[cont] = (konti >> conte) & 1;
      cont++;
    }
  }
    int konte = 0;
    printf("Número em BCD: ");
    for (int comt = 0; comt < cont; comt++) {
        printf("%d", bcd[comt]);
        konte++;
        while(konte == 4){
            printf(" ");
            konte = 0;
        }
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
    if (escolha == 3){
      printf("Qual número quer passar para hexadecimal: ");
      scanf("%d", &num);
      decimalhexa(num);
    }
    if (escolha == 4){
      printf("Qual número quer passar para BCD: ");
      scanf("%d", &num);
      decimalbcd(num);
    }
  }
  return 0;
}
