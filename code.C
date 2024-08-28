/**

 * Criado em 21 de Agosto 2024
 * Autor: André Castro
 * Questão 1:a) - 21/08/2024 18:28
 * Questão 1:b) - 21/08/2024 19:56
 * Questão 1:c) - 22/08/2024 17:22
 * Questão 1:d) - 26/08/2024 14:09
 * Questão 2 - 26/08/2024 14:41
 * Questão 3 - 28/08/2024 11:14

**/

#include <stdio.h>
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

void decimal16bits(int num){
  char coma2[16];
  int cont = 0;
  if (num == 0){
    printf("Complemento a 2 de 0 = 0");
  }
  else if (num > 0){
    printf("%d para binario:\n", num);
    while (num > 0){
      printf("%d / 2 = %d\n", num, num % 2);
      coma2[cont] = num % 2 + '0';
      cont++;
      num /= 2;
    }
    printf("Binário: ");
    for (int kont = cont - 1; kont >= 0; kont--){
      printf("%c", coma2[kont]);
    }
    printf("\n");
    printf("Complemento a 1: ");
    for (int kont = 0; kont < cont; kont++){
      if (coma2[kont] == '0'){
        coma2[kont] = '1';
      }
      else{
        coma2[kont] = '0';
      }
    }
    for (int i = cont - 1; i >= 0; i--){
      printf("%c", coma2[i]);
    }
    printf("\n");
    printf("Complemento a 2: ");
    int digitodesoma = 1;
    for (int kont = 0; kont < cont; kont++){
      if (coma2[kont] == '1' && digitodesoma == 1){
        coma2[kont] = '0';
      }
      else if (coma2[kont] == '0' && digitodesoma == 1){
        coma2[kont] = '1';
        digitodesoma = 0;
      }
    }
    if (digitodesoma == 1){
      coma2[cont] = '1';
      cont++;
    }
    for (int kont = cont - 1; kont >= 0; kont--){
      printf("%c", coma2[kont]);
    }
  }
  printf("\n\n");
}

void converterParaBinario(unsigned long long valor, int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%llu", (valor >> i) & 1);
    }
}

void rpf(float num) {
  unsigned int bits;
  memcpy(&bits, &num, sizeof(bits));
  int sinal = (bits >> 31) & 1;
  int expoente = (bits >> 23) & 0xFF;
  unsigned int fracao = bits & 0x7FFFFF;
  printf("Número: %f\n", num);
  printf("Sinal: %d\n", sinal);
  printf("Expoente: %d (0x%X) em binário: ", expoente - 127, expoente);
  converterParaBinario(expoente, 8);
  printf("\nFração em binário: ");
  converterParaBinario(fracao, 23);
  printf("\n\n");
}

void rpd(double num) {
  unsigned long long bits;
  memcpy(&bits, &num, sizeof(bits));
  int sinal = (bits >> 63) & 1;
  int expoente = (bits >> 52) & 0x7FF;
  unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;
  printf("Número: %lf\n", num);
  printf("Sinal: %d\n", sinal);
  printf("Expoente: %d (0x%X) em binário: ", expoente - 1023, expoente);
  converterParaBinario(expoente, 11);
  printf("\nFração em binário: ");
  converterParaBinario(fracao, 52);
  printf("\n\n");
}

int main(void) {
  int escolha = 0, num;
  float ero;
  while(escolha != 8){ 
    printf("1 - Decimal para binário\n2 - Decimal para octal\n3 - Decimal para hexadecimal\n4 - Decimal para BCD\n5 - Decimal para binário com sinal com 16 bits usando complemento a 2\n6 - Real para float, mostrando bits de sinal , expoente, expoente com viés e fração\n7 - Real para double, mostrando bits de sinal , expoente, expoente com viés e fração\n8 - Sair\n-> ");
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
      printf("Qual número quer passar de real para float, mostrando bits de sinal , expoente, expoente com viés e fração: ");
      scanf("%f", &ero);
      rpf(ero);
    }
    else if (escolha == 7){
      printf("Qual número quer passar de real para double, mostrando bits de sinal , expoente, expoente com viés e fração: ");
      scanf("%f", &ero);
      rpd(ero);
    }
  }
  return 0;
}
