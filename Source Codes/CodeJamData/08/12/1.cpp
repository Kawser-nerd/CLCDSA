#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int N, M, T;
int num[2005];
int all[2005][2005][2];
int state[2005];
int main() {
   int i, j, k, Case = 1, imp;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < M; i ++) {
	 scanf("%d", &num[i]);
	 for (j = 0; j < num[i]; j ++) {
	    scanf("%d%d", &all[i][j][0], &all[i][j][1]);
	    all[i][j][0] --;
	 }
      }
      memset(state, 0, sizeof(state));
      int ret = 0;
      imp = 0;
      int fini = 0;
      while (!fini) {
	 fini = 1;
	 for (i = 0; i < M; i ++) {
	    k = -1;
	    for (j = 0; j < num[i]; j ++) {
	       if (state[all[i][j][0]] == all[i][j][1])
		  break;
	       if (all[i][j][1] == 1)
		  k = j;
	    }
	    if (j >= num[i]) {
	       if (k == -1) {
		  fini = 1;
		  imp = 1;
		  break;
	       }
	       fini = 0;
	       state[all[i][k][0]] = 1;
	       ret ++;
	    }
	 }
      }
      printf("Case #%d:", Case ++);
      if (imp)
	 printf(" IMPOSSIBLE\n");
      else {
	 for (i = 0; i < N; i ++)
	    printf(" %d", state[i]);
	 printf("\n");
      }
   }
   return 0;
}

