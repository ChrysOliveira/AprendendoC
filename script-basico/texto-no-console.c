#include <stdio.h>

#define VARIAVEL_CONSTANTE 4

int main() {
  printf("Bem vindo ao nosso jogo de adivinhacao\n");

  int numero = 42;

  printf("O numero eh %d\n", numero);

  printf("Digite um numero\n");

  int numeroDigitado;

  scanf("%d", &numeroDigitado);
  printf("O numero digitado foi %d\n", numeroDigitado);

  if (numeroDigitado == 3) {
    printf("O numero digitado foi tres\n");
  } else {
    printf("O numero digitado nao foi 3\n");
  }

  int ehMaiorQueTres = (numeroDigitado > 3);

  if (ehMaiorQueTres) {
    printf("O numero eh maior que tres\n");
  } else {
    printf("O numero nao eh maior que tres\n");
  }

  for (int i = 0; i < 10; i++) {
    if (i == 8) {
      break;
    } else if (i < 0) {
      continue; // esse continue significa: vai pro proximo laco e nao execute o
                // resto do script
    }
    printf("%d - ", i);
  }

  printf("\nPra usar constantes temos que usar #INCLUDE %d\n",
         VARIAVEL_CONSTANTE);

  int testaWhile = 0;

  while (testaWhile <= 10) {
    printf("Testando o while %d\n", testaWhile);
    testaWhile++;
  }

  double numeroDouble = 2.2;

  double divisaoDouble = 2.2 / 2.0;

  printf("%.1f\n", divisaoDouble);
}
