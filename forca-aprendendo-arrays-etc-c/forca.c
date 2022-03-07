#include "forca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void abertura() {
  printf("********************************\n");
  printf("*        Jogo de Forca         *\n");
  printf("********************************\n");
}

void chuta(char chutes[26], int *quantidadesDeChutesDados) {
  char chute;
  scanf(" %c", &chute);

  chutes[(*quantidadesDeChutesDados)] = chute;
  (*quantidadesDeChutesDados)++;
}

void desenhaForca(char palavraSecreta[20], char chutes[26],
                  int quantidadesDeChutesDados) {
  for (int i = 0; i < strlen(palavraSecreta); i++) {

    int achou = jaChutou(palavraSecreta[i], chutes, quantidadesDeChutesDados);

    if (achou) {
      printf("%c ", palavraSecreta[i]);
    } else {
      printf("_ ");
    }
  }

  printf("\n");
}

void adicionaPalavra() {

  char quer;

  printf("Voce gostaria de adicionar uma nova palavra no jogo? (S/N)\n");
  scanf(" %c", &quer);

  if (quer == 'S') {

    char novaPalavra[20];

    printf("Qual a nova palavra?\n");
    scanf("%s", novaPalavra);

    FILE *f;

    f = fopen("palavras.txt", "r+");

    if (f == 0) {
      printf("Desculpe, banco de dados nao disponivel\n\n");
    }

    int quantidade;
    fscanf(f, "%d", &quantidade);
    quantidade++;

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", quantidade);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novaPalavra);

    fclose(f);
  } else {
    exit(0);
  }
}

void escolhePalavra(char palavraSecreta[20]) {
  FILE *f;
  f = fopen("palavras.txt", "r");

  if (f == 0) {
    printf("Desculpe, banco de dados nao disponivel\n\n");
    exit(1);
  }

  int qntDePalavras;
  fscanf(f, "%d", &qntDePalavras);

  srand(time(0));
  int randomico = rand() % qntDePalavras;

  for (int i = 0; i < randomico;
       i++) { // OBSERVACAO: COMO O PONTEIRO "f" JA LEU A PRIMEIRA, LINHA, ELE
              // VAI COMECAR A LER A PARTIR DAQUI
    fscanf(f, "%s", palavraSecreta);
  }

  fclose(f);
}

int enforcou(char palavraSecreta[20], char chutes[26],
             int quantidadesDeChutesDados) {

  int erros = 0;

  for (int i = 0; i < quantidadesDeChutesDados; i++) {

    int existe = 0;

    for (int j = 0; j < strlen(palavraSecreta); j++) {
      if (chutes[i] == palavraSecreta[j]) {
        existe = 1;
        break;
      }
    }
    if (!existe)
      erros++;
  }

  return erros >= 5;
}

int acertou(char palavraSecreta[20], char chutes[26],
            int quantidadesDeChutesDados) {
  for (int i = 0; i < strlen(palavraSecreta); i++) {
    if (!jaChutou(palavraSecreta[i], chutes, quantidadesDeChutesDados)) {
      return 0;
    }
  }
  return 1;
}

int jaChutou(char letraChutada, char chutes[26], int quantidadesDeChutesDados) {
  int achou = 0;

  for (int j = 0; j < quantidadesDeChutesDados; j++) {
    if (chutes[j] == letraChutada) {
      achou = 1;
      break;
    }
  }

  return achou;
}

int main(int argc, char *argv[]) {
  char palavraSecreta[20];
  escolhePalavra(palavraSecreta);
  /* printf("%s\n", palavraSecreta);
  se fossemos definir as letras do array index por index o ultimo deve ter o
  valor "\1" para indicar fim do uso */

  char chutes[26];
  int quantidadesDeChutesDados = 0;

  abertura();

  do {

    desenhaForca(palavraSecreta, chutes, quantidadesDeChutesDados);

    chuta(chutes, &quantidadesDeChutesDados);

  } while (!acertou(palavraSecreta, chutes, quantidadesDeChutesDados) &&
           !enforcou(palavraSecreta, chutes, quantidadesDeChutesDados));

  adicionaPalavra();
}
