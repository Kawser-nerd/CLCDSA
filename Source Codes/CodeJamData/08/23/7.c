#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, cases;
  scanf("%d\n", &cases);
  for (i = 1; i <= cases; i++)
  {
    int K;
    int indices[101];
    int deck[1000001];
    int numbind, j;
    int asignados;
    int actual;
    scanf("%d\n", &K);
    scanf("%d", &numbind);
    for (j = 0; j < numbind; j++)
      scanf(" %d", indices + j);
    indices[numbind] = -1;
    /**/
    for (j=0; j < K; j++) deck[j] = 0;
    asignados = 0;
    actual = 0;
    while (asignados < K) {
      deck[actual] = ++asignados;
      if (asignados == K) break;
      /* Avanzar al siguiente hueco */
      for (j = 0; j < asignados + 1; j++) {
	do {
	  actual++;
	  if (actual == K) actual = 0;
	} while (deck[actual] != 0);
      }
      /* fin avanzar */
    }
    /**/
    printf("Case #%d:", i);
    j = 0;
    while (indices[j] != -1)
    {
      printf(" %d", deck[indices[j] - 1]);
      j++;
    }
    printf("\n");
    flush(stdout);
  }
}

