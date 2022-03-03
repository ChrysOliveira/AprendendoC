#include <stdio.h>
#include <string.h>

void abertura() {
  printf("********************************\n");
  printf("*        Jogo de Forca         *\n");
  printf("********************************\n");
}

void chuta(char chutes[26], int *tentativas) {
  char chute;
  scanf(" %c", &chute);

  chutes[(*tentativas)] = chute;
  (*tentativas)++;
}

int jaChutou(char letraChutada, char chutes[26], int tentativas) {
  int achou = 0;

  for (int j = 0; j < tentativas; j++) {
    if (chutes[j] == letraChutada) {
      achou = 1;
      break;
    }
  }

  return achou;
}

void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas) {
  for (int i = 0; i < strlen(palavraSecreta); i++) {

    int achou = jaChutou(palavraSecreta[i], chutes, tentativas);

    if (achou) {
      printf("%c ", palavraSecreta[i]);
    } else {
      printf("_ ");
    }
  }

  printf("\n");
}

void escolhePalavra(char palavraSecreta[20]) {
  sprintf(palavraSecreta, "MELANCIA");
}

int enforcou(int tentativas) {

  for (int i = 0; i < tentativas; i++) {
  }
}

int main(int argc, char *argv[]) {
  char palavraSecreta[20];
  escolhePalavra(palavraSecreta);
  /* printf("%s\n", palavraSecreta);
  se fossemos definir as letras do array index por index o ultimo deve ter o
  valor "\1" para indicar fim do uso */

  char chutes[26];
  int tentativas = 0;

  int acertou = 0;
  int enforcou = 0;

  abertura();

  do {

    desenhaForca(palavraSecreta, chutes, tentativas);

    chuta(chutes, &tentativas);

  } while (!acertou && !enforcou);
}
