#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define oo 10000000
int N, M, C;
int h1, h2, w1, w2;
int info[2][1005][2];
char tmp[100];
int main() {
   int i, j, k, Case = 1;
   int n[2];
   scanf("%d", &C);
   while (C --) {
      scanf("%d", &N);
      n[0] = n[1] = 0;
      h1 = w1 = oo;
      h2 = w2 = -1;
      for (i = 0; i < N; i ++) {
	 scanf("%d%d", &j, &k);
	 scanf("%s", tmp);
	 while (getchar() != '\n');
	 if (tmp[0] == 'B') {
	    info[0][n[0]][0] = j;
	    info[0][n[0]][1] = k;
	    h1 = min(h1, j);
	    h2 = max(h2, j);
	    w1 = min(w1, k);
	    w2 = max(w2, k);
	    n[0] ++;
	 }
	 else {
	    info[1][n[1]][0] = j;
	    info[1][n[1]][1] = k;
	    n[1] ++;
	 }
      }
      printf("Case #%d:\n", Case ++);
      scanf("%d", &M);
      while (M --) {
	 scanf("%d%d", &j, &k);
	 if (h1 <= j && j <= h2 && w1 <= k && k <= w2)
	    printf("BIRD\n");
	 else {
	    int h12, h22, w12, w22;
	    h12 = min(h1, j);
	    h22 = max(h2, j);
	    w12 = min(w1, k);
	    w22 = max(w2, k);
	    for (i = 0; i < n[1]; i ++)
	       if (h12 <= info[1][i][0] && info[1][i][0] <= h22 && w12 <= info[1][i][1] && info[1][i][1] <= w22)
		  break;
	    if (i >= n[1])
	       printf("UNKNOWN\n");
	    else
	       printf("NOT BIRD\n");
	 }
      }
   }
   return 0;
}

