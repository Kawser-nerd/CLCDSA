#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVET 1000005
#define TRUE 1
#define FALSE 0

int cmpAsc(const void *a, const void *b);       /* ordena em forma ascendente */
int cmpDesc(const void *a, const void *b);      /* ordena em forma decrescente */
void leVetor(int vet[], int n);                 /* le o vetor vet, tamanho n */
void printVetor(int vet[], int n);              /* imprime o vetor vet */
void montaDeck(int vetDeck[], int deck);

int main(void) {

    int t, i;                       /* casos de teste */
    int caso = 1;                /* caso atual */    
    int resultado = -1;          /* resultado da computação */
    int deck;                    /* tamanho do deck */
    int numIndices;              /* quantos indices */

    int *vetDeck = (int *) malloc(sizeof(int) * MAXVET);
    int *vetIndices = (int *) malloc(sizeof(int) * MAXVET);

    scanf("%d", &t);

    for (caso=1; caso<=t; caso++) {
        scanf("%d", &deck);

        for (i=1; i<=deck; i++)
            vetDeck[i] = -1;

        montaDeck(vetDeck, deck+1);

        scanf("%d", &numIndices);

        leVetor(vetIndices, numIndices);

        printf("Case #%d: ", caso);

        for (i=0; i<numIndices; i++)
            printf("%d ", vetDeck[vetIndices[i]]);

        printf("\n");
    }

    return 0;
}

int cmpAsc(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;

    return *x - *y;
}

int cmpDesc(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;

    return *y - *x;
}

void leVetor(int vet[], int n) {
     int j;

     for (j=0; j<n; j++)
         scanf("%d", &vet[j]);
}

void printVetor(int vet[], int n) {
     int j;

     for (j=0; j<n; j++)
         printf("%d ", vet[j]);
}

void montaDeck(int vetDeck[], int deck) {

     int proximo = 1, cvazio = 0, i;

     for (i=1; TRUE ;i++) {
         if (vetDeck[i] == -1) 
            cvazio++;

         /* conta a posição do proximo vazio */
         if (cvazio == proximo) {
            vetDeck[i] = proximo++;
            cvazio = 0;
         }   

         /* já achou lugar para todos */
         if (proximo == deck)
            return ;

         if (i==deck)
            i = 1;
     }
}
