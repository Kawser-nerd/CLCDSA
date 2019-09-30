// Code Kludge/Jam Round 1C, bastard son of sequel III

// insert joke about remembering c input here...
// (goal for today: be less dumb about time)
// 5am this time, woof.

#include <stdio.h>
#include <stdlib.h>

// Less-than-legendary reinvented wheels for c input (java.util.Scanner, anyone?)
int getInt() {int i; scanf("%d", &i); getchar(); return i;}

#define MAAX 10
#define MAAXLINE 100+2

void reverse(int *p, int n) {
   int i = 0, t;
   while (i < n) {
      // swap p[i] and p[n-1]
      t = p[i];
      p[i] = p[n-1];
      p[n-1] = t;
      // next!
      i++;
      n--;
   }
   return;
}

int permute(int *p, int n) {
   int i, k = -1, l = 0;
   for (i=0; i<n-1; i++) {
      if (p[i+1] > p[i]) {
         if (i > k) k = i;
      }
   }
   if (k == -1) return 0;
   for (i=0; i<n; i++) {
      if (p[k] < p[i]) {
         if (i > l) l = i;
      }
   }
   // swap p[k] and p[l]
   i = p[k];
   p[k] = p[l];
   p[l] = i;

   // reverse remainder
   reverse(&p[k+1], n-(k+1));
   return 1;
}


int main() {
   int q, cases;

   int n, i;
   char carz[MAAX][MAAXLINE];
   char *c;
   char cc;
   int perm[MAAX];
   int lc[26];
   unsigned long long winz;

   cases = getInt();

   for (q=1; q<=cases; q++) {
      printf("Case #%d: ", q);

      n = getInt();
      // get trains
      //j = getString(order, sizeof order);
      //s = order;
      for (i=0; i<n; i++) {
         c = carz[i];
         while ((cc = getc(stdin)) && (cc >= 'a') && (cc <= 'z')) {
            *c++ = cc;
         }
         *c = 0;
         //if (cc == ' ') getc(stdin);
      }

      winz = 0;
      // generate first permutation
      for (i=0; i<n; i++) perm[i] = i;

      do {
         for (i=0; i<26; i++) lc[i] = 0; // reset lettercounts
         cc = carz[perm[0]][0];
         for (i=0; i<n; i++) {
            c = carz[perm[i]];
            while (*c) {
               if (*c != cc) {
                  if (lc[*c-'a'] == 0) cc = *c;
                  else goto bail;
               }
               lc[cc-'a']++;
               c++;
            }
         }
         winz++;
bail:
         ;
      } while (permute(perm, n)); 

      printf("%llu\n", winz);
// per case breakpoint
   }
// hold output breakpoint
   return 0;
}