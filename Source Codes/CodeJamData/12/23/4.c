#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 22000000

typedef struct {
   int ind;
   long long sum;
} sub;

sub *subs;

int compare(const sub *a, const sub *b) {
   if ((*a).sum < (*b).sum) return -1;
   else if ((*a).sum > (*b).sum) return +1;
   else return 0;
}


void run(const long long num[600]) {

   int i, j, k, sp=0;

   for(i=0; i<500; i++)
   for(j=i+1; j<500; j++)
   for(k=j+1; k<500; k++) {
      subs[sp].ind = 1048576 * k + 1024 * j + i;
      subs[sp].sum = num[i] + num[j] + num[k]; sp++;
   }
   qsort(subs, sp, sizeof(sub), compare);

   for(i=0; i<sp; i++)
      if (subs[i].sum == subs[i+1].sum) {
         long long n1,n2,n3,m1,m2,m3;

         n1 = num[subs[i].ind % 1024];
         n2 = num[(subs[i].ind / 1024) % 1024];
         n3 = num[subs[i].ind / 1048576];
         m1 = num[subs[i+1].ind % 1024];
         m2 = num[(subs[i+1].ind / 1024) % 1024];
         m3 = num[subs[i+1].ind / 1048576];

         printf("%lld %lld %lld\n", m1, m2, m3);
         printf("%lld %lld %lld\n", n1, n2, n3);
         if (m1+m2+m3 != n1+n2+n3) printf("ERROR!!!!!\n");
         return;
      }

}


int main() {
   int m, i, j;

   subs = (sub *)malloc(sizeof(sub) * NUM);

   scanf("%d", &m);
   for(i=0; i<m; i++) {
      int n;
      long long num[600];

      scanf("%d", &n); // n=500.
      for(j=0; j<n; j++)
         scanf("%lld", &num[j]);

      printf("Case #%d:\n", i+1);
      run(num);
   }

   free(subs); 
}
