#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test_case(int n, double width, double len, double rad[]) {
   int i, j, newline;
   double x[6000], y[6000], rrr;
   int xt, yt;
   int indices[6000];

   for(i=0; i<n; i++) indices[i] = i;
   for(i=n-2; i>=0; i--) 
   for(j=0; j<=i; j++) {
      if (rad[indices[j]] < rad[indices[j+1]]) {
         xt = indices[j]; indices[j] = indices[j+1]; indices[j+1] = xt;
      }
   }

   // Radii sorted.

//for(i=0; i<n; i++) printf("%lf ---\n", rad[indices[i]]);

   x[indices[0]] = y[indices[0]] = 0;
   for(i=1; i<n; i++) {

again:
      xt = random() % ((int)width);
      yt = random() % ((int)len);
//printf("TEST---\n");
      for(j=0; j<i; j++) {
         if ((x[indices[j]]-xt)*(x[indices[j]]-xt) + (y[indices[j]]-yt)*(y[indices[j]]-yt) < (rad[indices[j]] + rad[indices[i]])*(rad[indices[j]]+rad[indices[i]]) + 0.5)
         goto again;
      }
      x[indices[i]] = xt; y[indices[i]] = yt;
   }

   for(i=0; i<n; i++) {
      printf("%lf %lf ", x[i], y[i]); 
   }
   printf("\n");
}


int main() {
   int num, i, n, j;
   double width, len;
   double rad[6000];

   scanf("%d", &num);
   for(i=0; i<num; i++) {
      scanf("%d %lf %lf", &n, &width, &len);

      for(j=0; j<n; j++) 
         scanf("%lf", &rad[j]);

      printf("Case #%d: ", i+1);
      test_case(n, width, len, rad);
   }

   return 0;
}
