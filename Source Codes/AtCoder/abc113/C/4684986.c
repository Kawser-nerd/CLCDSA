#include <stdio.h>
#include <stdlib.h>

struct pair{
  int p;
  int y;
  int num;
};

int compare_y(const void *x, const void *y) {
  return ((struct pair *)x)->y - ((struct pair *)y)->y;
}

int compare_num(const void *x, const void *y) {
  return ((struct pair *)x)->num - ((struct pair *)y)->num;
}

int main() {
  int N,M;
  scanf("%d %d",&N,&M);
  struct pair PY[M];
  int check[N];
  for (int i = 0; i < N; i++) {
    check[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d",&PY[i].p,&PY[i].y);
    PY[i].num = i;
  }
  qsort(PY,M,sizeof(struct pair),compare_y);

  for (int i = 0; i < M; i++) {
    int pref = PY[i].p-1;
    int city = check[pref];
    PY[i].y = city+1;
    check[pref] += 1;
  }

  qsort(PY,M,sizeof(struct pair),compare_num);

  for (int i = 0; i < M; i++) {
    printf("%06d%06d\n",PY[i].p,PY[i].y);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&PY[i].p,&PY[i].y);
     ^