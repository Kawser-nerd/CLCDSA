#include <stdio.h>
#include <stdlib.h>
int N,M,Q;
int *a,*b,*y,*v,*w;
int *par = 0;
int *rnk = 0;
int *S;
typedef struct MM {
  int a;
  int b;
  int y;
} MM;
MM *Y;
typedef struct QQ {
  int id;
  int v;
  int w;
  int ans;
} QQ;
QQ *V;
void init()
{
  if (par == 0) {
    par = (int*)malloc(sizeof(int)*N);
    rnk = (int*)malloc(sizeof(int)*N);
    S = (int*)malloc(sizeof(int)*N);
  }
  int i;
  for (i=0; i<N; i++) {
    par[i] = i;
    rnk[i] = 0;
    S[i] = 1;
  }
}
int root(int x)
{
  if (par[x] == x) {
    return x;
  } else {
    par[x] = root(par[x]);
    return par[x];
  }
}
void unite(int x, int y)
{
  x = root(x);
  y = root(y);
  if (x == y) {
    return;
  }
  if (rnk[x] < rnk[y]) {
    par[x] = y;
    S[y] += S[x];
  } else {
    par[y] = x;
    S[x] += S[y];
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}
int cmp_y(const void *a, const void *b)
{
  return ((MM*)b)->y - ((MM*)a)->y;
}
int cmp_w(const void *a, const void *b)
{
  return ((QQ*)b)->w - ((QQ*)a)->w;
}
int cmp_id(const void *a, const void *b)
{
  return ((QQ*)a)->id - ((QQ*)b)->id;
}
int main()
{
  int i;
  scanf("%d %d",&N,&M);
  Y = (MM*)malloc(sizeof(MM)*M);
  for (i=0; i<M; i++) {
    scanf("%d %d %d",&(Y[i].a),&(Y[i].b),&(Y[i].y));
  }

  scanf("%d",&Q);
  V = (QQ*)malloc(sizeof(QQ)*Q);
  for (i=0; i<Q; i++) { 
    scanf("%d %d",&(V[i].v),&(V[i].w));
    V[i].id = i;
    V[i].ans = -1;
  }

  qsort(Y, M, sizeof(MM), cmp_y);
  qsort(V, Q, sizeof(QQ), cmp_w);
  init();

  int j;
  i = 0;
  j = 0;
  while (j<Q) {
    while (i<M) {
      if (V[j].w < Y[i].y) {
        unite(Y[i].a-1, Y[i].b-1);
        i++;
      } else {
        break;
      }
    }
    V[j].ans = S[root(V[j].v-1)];
    while (j<Q-1) {
      if (V[j+1].w == V[j].w) {
        V[j+1].ans = S[root(V[j+1].v-1)];
        j++;
      } else {
        break;
      }
    }
    j++;
  }

  qsort(V, Q, sizeof(QQ), cmp_id);
  for (j=0; j<Q; j++) {
    printf("%d\n",V[j].ans);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:75:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&(Y[i].a),&(Y[i].b),&(Y[i].y));
     ^
./Main.c:81:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&Q);
   ^
./Main.c:84:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&(V[i].v),&(V[i].w));
     ^