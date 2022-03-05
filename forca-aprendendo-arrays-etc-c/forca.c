#include <stdio.h>
#include <string.h>

void abertura();
void chuta(char chutes[26], int *quantidadesDeChutesDados);
int jaChutou(char letraChutada, char chutes[26], int quantidadesDeChutesDados);
void desenhaForca(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados);
void escolhePalavra(char palavraSecreta[20]);
int enforcou(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados);
int acertou(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados);


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

void desenhaForca(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados) {
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

void escolhePalavra(char palavraSecreta[20]) {
  sprintf(palavraSecreta, "MELANCIA");
}

int enforcou(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados) {
  
  int erros = 0;

  for (int i = 0; i < quantidadesDeChutesDados; i++) {
    
    int existe = 0;
    
    for (int j = 0; j < strlen(palavraSecreta); j++) {
      if(chutes[i] == palavraSecreta[j]){
        existe = 1;
        break;
      }
    }
   if(!existe) erros++; 
  }

  return erros >=5;
}

int acertou(char palavraSecreta[20], char chutes[26], int quantidadesDeChutesDados){
  for (int i = 0; i < strlen(palavraSecreta); i++) {
    if(!jaChutou(palavraSecreta[i], chutes, quantidadesDeChutesDados)){
      return 0;
    }
  }
  return 1;
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

  } while (!acertou(palavraSecreta, chutes, quantidadesDeChutesDados) && !enforcou(palavraSecreta, chutes, quantidadesDeChutesDados));
}
