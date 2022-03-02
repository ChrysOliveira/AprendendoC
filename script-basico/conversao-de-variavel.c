#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  double valor = 3 / 2.0;

  printf("%f\n", valor);

  int valorInteiro = (int)valor;

  printf("%d\n", valorInteiro);

  int a = 3;
  int b = -3;

  printf("%d %d\n", a, b);

  printf("Se usar o abs (que altera numeros negativos para positivos mas nao "
         "faz vice-versa)\n");

  printf("%d %d\n", a, abs(b));

  printf("USANDO A FUNCAO RAND:\n");

  int c = rand(); // GERA UM NUMERO ALEATORIO

  int d = c % 100; // RETORNA UM NUMERO ENTRE 0 E 99

  printf("Numero aleatorio: %d\n",
         c); // vai ser sempre o mesmo numero pois a logica do rand vai ser a
             // mesma por ja estar compilado

  int segundos = time(0);
  srand(segundos);

  int e = rand() % 100;

  printf("Numero aleatorio que muda!: %d\n", e);

  
}
