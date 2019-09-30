#include <stdio.h>
#include <stdlib.h>

// Number of digits.

int num_d(int N) {
   int i=0;

   while(N>0) {
      N/=10; i++;
   }
   return i;
}

// Power of 10.

int power_10(int m) {
   int res=1;

   while(m) {m--; res*=10; }

   return res;
}

// Find number of rotations of N which are > N and <= max.

int find_rotations(int N, int max) {
   int tmpN = N;
   int digits = num_d(N), res=0;

   do {
      tmpN = (tmpN%10) * power_10(digits-1) + (tmpN/10);
      if (tmpN > N && tmpN <= max) res++;
   } while (tmpN != N);

   return res;
}

// Find number of pairs (m,n), a<=m<n<=b such that n is a rotation of m.

int find_pairs(int a, int b) {
   int i, tot=0;

   for(i=a; i<b; i++) 
      tot += find_rotations(i, b);
   return tot;
}

// Main

int main() {
   int num, i, a, b;

   scanf("%d", &num);
   for(i=0; i<num; i++) {
      scanf("%d %d", &a, &b);
      printf("Case #%d: %d\n", i+1, find_pairs(a, b));
   }
}
