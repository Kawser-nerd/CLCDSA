#include <stdio.h>
#include <stdlib.h>

int compar(const int *val1, const int *val2) {
    if ( *val1 < *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
}

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  int x[m];
  for(int i = 0; i < m; ++i) scanf("%d",&x[i]);
  qsort(x, m, sizeof(int),(int (*)(const void *, const void *))compar);
  int answer = 0;
  if(m == 1 || n >= m){
    answer = 0;
  }else{
    int deltax[m-1];
    int num = m - n;
    for(int i = 0; i < m - 1; ++i) deltax[i] = x[i+1] - x[i];
    qsort(deltax, m-1, sizeof(int),(int (*)(const void *, const void *))compar);
    for(int i = 0; i < num; ++i) answer += deltax[i];
  }
  printf("%d\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:18:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < m; ++i) scanf("%d",&x[i]);
                              ^