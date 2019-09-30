#include <stdio.h>
#include <stdlib.h>

#define MAX 12000

int run_test(int d[], int l[], int n, int dist) {
   int max[MAX];
   int i, j;
   int len, l2;

   max[0] = d[0];
   if (l[0] < d[0]) return 0;

   for(i=1; i<n; i++) {
      len = -1;
      for(j=0; j<i; j++) 
         if (d[j]+max[j] >= d[i]) {   // Can go from j -> i.
            l2 = d[i]-d[j];
            if (l2 > l[i]) l2 = l[i];
            if (l2 > len) len = l2;
	 }
      if (len == -1) return 0;
      max[i] = len;
   }
   // Final check.

   for(i=0; i<n; i++) 
      if (d[i] + max[i] >= dist) return 1;
   return 0;
}


int main() {
   int num, i, j;
   int d[MAX], l[MAX], dist;

   scanf("%d", &num);
   for(i=0; i<num; i++) {
      int n;

      scanf("%d", &n);
      for(j=0; j<n; j++)
         scanf("%d %d", &d[j], &l[j]);
      scanf("%d", &dist);
      printf("Case #%d: ", i+1);
      if (run_test(d, l, n, dist)) printf("YES"); else printf("NO");
      printf("\n");
   }

   return 0;
}
