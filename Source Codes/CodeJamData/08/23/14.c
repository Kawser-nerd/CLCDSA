#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct linkedlist {
int *p;
linkedlist *next;
linkedlist *prev;
} linkedlist;

int main(int argc, char **argv) {
  int numcase = -1;
  scanf("%d\n", &numcase);
  for (int i = 0; i < numcase; i++) {
    int K = -1, n = -1;
    scanf("%d\n", &K);
    scanf("%d", &n);
    int d[n];
    for (int j = 0; j < n; j++) {
      scanf("%d", &(d[j]));
    }
    
    int *k = (int*)calloc(K, sizeof(int));
    linkedlist *head = (linkedlist*)malloc(K*sizeof(linkedlist));
    linkedlist *actfree = head, *actprev = NULL;
    for (int j = 0; j < K; j++) {
      actfree->p = &(k[j]);
      if (actprev) {
        actprev->next = actfree;
        actfree->prev = actprev;
      }
      actprev = actfree;
      actfree++;
    }
    actprev->next = head;
    head->prev = actprev;
    
    int actcount = 1;
    actfree = head;
    
    for (int j = 1; j <= K; j++) {
      while (actcount != j) {
        actcount++;
        actfree = actfree->next;
      }
      *(actfree->p) = j;
      actfree->prev->next = actfree->next;
      actfree->next->prev = actfree->prev;
      actcount = 0;
    }
    
    printf("Case #%d:", i+1);
    for (int j = 0; j < n; j++) {
      printf(" %d", k[d[j]-1]);
    }
    printf("\n");
    free(k);
    free(head);
  }
  return 0;
}
