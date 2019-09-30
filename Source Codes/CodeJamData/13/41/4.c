#include <stdio.h>
#include <stdlib.h>

#define TRUE      1
#define FALSE     0
#define MOD       1000002013ll

struct range {
   int s;
   int e;
   int p;
   int place;
};

int N;
int M;

int nP;
struct range people[1000001];
struct range curP[1001];

int typeSort;

void handlecase();

int min (int n1, int n2) {
   return n1 < n2 ? n1 : n2;
}

void sort (int start, int end, struct range *p) {
   if (start >= end) {
      return;
   }
   int mid = (start + end) / 2;
   sort (start, mid, p);
   sort (mid + 1, end, p);
   int i;
   int place1 = start;
   int place2 = mid + 1;
   struct range newP[end - start + 1];
   for (i = 0; i < end - start + 1; i++) {
      if (place1 > mid) {
         newP[i] = p[place2++];
      } else if (place2 > end) {
         newP[i] = p[place1++];
      } else {
         if ((typeSort == 0 && (p[place1].s < p[place2].s || (p[place1].s == p[place2].s && p[place1].e < p[place2].e))) || (typeSort == 1 && (p[place1].e > p[place2].e || (p[place1].e == p[place2].e && p[place1].s > p[place2].s)))) {
            newP[i] = p[place1++];
         } else {
            newP[i] = p[place2++];
         }
      }
   }
   for (i = 0; i < end - start + 1; i++) {
      p[i + start] = newP[i];
   }
}

int main() {
   freopen ("a.in", "r", stdin);
   freopen ("a.out", "w", stdout);
   int n;
   scanf ("%d ", &n);
   int i;
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handlecase();
   }
   return 0;
}

long long findAmo (int s, int e) {
   if (s == e) {
      return 0ll;
   }
   long long diff = (long long) (e - s);
   long long lN = (long long) N;
   long long res = ((lN * (lN + 1ll)) / 2ll) - (((lN - diff) * (lN + 1ll - diff)) / 2ll);
   return res;
}

int getSwapAmo (int s1, int e1, int s2, int e2) {
   
   long long gain = findAmo (s1, e1) + findAmo (s2, e2);
   long long lose = findAmo (s1, e2) + findAmo (s2, e1);
   long long diff = gain - lose;
   return diff % MOD;
}


void handlecase() {
   scanf ("%d %d ", &N, &M);
   int i, j;
   for (i = 0; i < M; i++) {
      scanf ("%d %d %d ", &people[i].s, &people[i].e, &people[i].p);
   }
   int lose = 0;
   nP = M;
   for (i = 0; i < nP; i++) {
      // Find person intersecting and furthest away
      int furEnd = 0;
      int ind = -1;
      for (j = 0; j < nP && people[i].p > 0; j++) {
         if (people[j].s > people[i].s && people[j].s <= people[i].e && people[j].e > people[i].e && people[j].p > 0) {
            if (people[j].e > furEnd) {
               furEnd = people[j].e;
               ind = j;
            }
         }
      }
      // Make a swap
      if (ind != -1) {
         if (people[i].p > people[ind].p) {
            // We swap completely with them, cloning us
            long long sw = (long long) getSwapAmo (people[i].s, people[i].e, people[ind].s, people[ind].e);
            sw *= (long long) people[ind].p;
            sw %= MOD;
            lose += (int) sw;
            lose %= (int) MOD;
            // Set up new group
            people[nP].s = people[ind].s;
            people[nP].e = people[i].e;
            people[nP].p = people[ind].p;
            nP++;
            people[ind].s = people[i].s;
            people[i].p -= people[ind].p;
            i--;
         } else {
            long long sw = (long long) getSwapAmo (people[i].s, people[i].e, people[ind].s, people[ind].e);
            sw *= (long long) people[i].p;
            sw %= MOD;
            lose += (int) sw;
            lose %= (int) MOD;
            // Set up new group
            people[nP].s = people[i].s;
            people[nP].e = people[ind].e;
            people[nP].p = people[i].p;
            nP++;
            people[i].s = people[ind].s;
            people[ind].p -= people[i].p;
            i--;
         }
      }
   }
   printf ("%d\n", lose);
}

