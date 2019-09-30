#include <stdio.h>
#include <stdlib.h>

void compute(int lvl, int n[], int p[]) {
   int i, j, t;
   int order[2000];

   for(i=0; i<lvl; i++) order[i] = i;

   for(i=lvl-1; i>=1; i--) 
   for(j=0; j<i; j++) {
      if (n[order[j]]*p[order[j+1]] > n[order[j+1]]*p[order[j]]) {
         t = order[j];
         order[j] = order[j+1];
         order[j+1] = t;
      }
   }

   for(i=0; i<lvl; i++) printf("%d ", order[i]);
   printf("\n");
}


int main() {
   int num, i, j;

   scanf("%d", &num);
   for(i=0; i<num; i++) {
      int n[2000], p[2000], lvl;

      scanf("%d", &lvl);
      for(j=0; j<lvl; j++)
         scanf("%d", &n[j]);
      for(j=0; j<lvl; j++)
         scanf("%d", &p[j]);

      printf("Case #%d: ", i+1);
      compute(lvl, n, p);
   }

   return 0;
}
