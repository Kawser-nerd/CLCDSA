#include <stdio.h>
#include <string.h>

#define MAXM 10123
#define INF 10*MAXM

#define Min(a,b) ((a)<(b)?(a):(b))

/* 1 = AND */
int G[MAXM], C[MAXM], L[MAXM], LC[MAXM];

int memo[MAXM][5];

int eval(int u, int m, int v) {
  int res = INF;

  if (u >= (m+1)/2) {
    if (v == L[u-1-(m-1)/2])
      return 0;
    else
      return INF;
  }
  
  if (memo[u][v] != -1)
    return memo[u][v];

  if (G[u-1] == 1) {
    if (v == 1)
      res = Min(res, eval(2*u, m, 1) + eval(2*u+1, m, 1));
    if (v == 0) {
      int a, b, c;
      a = eval(2*u, m, 0) + eval(2*u+1, m, 0);
      b = eval(2*u, m, 0) + eval(2*u+1, m, 1);
      c = eval(2*u, m, 1) + eval(2*u+1, m, 0);
      res = Min(res, Min(a, Min(b, c)));
    }
  } else {
    if (v == 0)
      res = Min(res, eval(2*u, m, 0) + eval(2*u+1, m, 0));
    if (v == 1) {
      int a, b, c;
      a = eval(2*u, m, 1) + eval(2*u+1, m, 1);
      b = eval(2*u, m, 0) + eval(2*u+1, m, 1);
      c = eval(2*u, m, 1) + eval(2*u+1, m, 0);
      res = Min(res, Min(a, Min(b, c)));
    }
  }

  if (C[u-1]) {
    G[u-1] = (G[u-1]+1)%2;

    /*  */
    if (G[u-1] == 1) {
      if (v == 1)
	res = Min(res, eval(2*u, m, 1) + eval(2*u+1, m, 1) +1);
      if (v == 0) {
	int a, b, c;
	a = eval(2*u, m, 0) + eval(2*u+1, m, 0) +1;
	b = eval(2*u, m, 0) + eval(2*u+1, m, 1) +1;
	c = eval(2*u, m, 1) + eval(2*u+1, m, 0) +1;
	res = Min(res, Min(a, Min(b, c)));
      }
    } else {
      if (v == 0)
	res = Min(res, eval(2*u, m, 0) + eval(2*u+1, m, 0) +1);
      if (v == 1) {
	int a, b, c;
	a = eval(2*u, m, 1) + eval(2*u+1, m, 1) +1;
	b = eval(2*u, m, 0) + eval(2*u+1, m, 1) +1;
	c = eval(2*u, m, 1) + eval(2*u+1, m, 0) +1;
	res = Min(res, Min(a, Min(b, c)));
      }
    }
    /*  */

    G[u-1] = (G[u-1]+1)%2;
  }

  return memo[u][v] = res;
}
 
int main() {
  int t, cases = 1;
  int m, v, i, k, nchang, res;
  int a, modf;

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &v);

    nchang = 0;
    for (i = 0; i < (m-1)/2; i++) {
      scanf("%d%d", &G[i], &C[i]);
      if (C[i]) LC[nchang++] = i;
    }
    for (i = 0; i < (m+1)/2; i++)
      scanf("%d", &L[i]);

/*     res = 1000000; */
/*     for (a = 0; a < (1<<nchang); a++) { */
/*       modf = 0; */

/*       for (k = 0; k < nchang; k++) */
/* 	if (a & (1<<k)) { */
/* 	  G[LC[k]] = (G[LC[k]]+1)%2; */
/* 	  modf++; */
/* 	} */

/*       if (eval(1, m) == v) */
/* 	if (modf < res) res = modf; */

/*       for (k = 0; k < nchang; k++) */
/* 	if (a & (1<<k)) */
/* 	  G[LC[k]] = (G[LC[k]]+1)%2; */
/*     } */

    memset(memo, -1, sizeof(memo));
    res = eval(1, m, v);
    
    printf("Case #%d: ", cases++);
    if (res >= INF)
      printf("IMPOSSIBLE\n");
    else printf("%d\n", res);
  }

  return 0;
}
