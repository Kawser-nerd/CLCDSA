#include <stdio.h>
#include <stdlib.h>

int compar(const int *val1, const int *val2) {//??????
    if ( *val1 < *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
}

int main(){
  int n;
  scanf("%d",&n);
  int d[n];
  for(int i = 0; i < n; ++i) scanf("%d",&d[i]);
  qsort(d, n, sizeof(int),(int (*)(const void *, const void *))compar);
  int answer = 1;
  for(int i = 0; i < n - 1; ++i){
    if(d[i+1] > d[i]) answer += 1;
  }
  printf("%d\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:18:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < n; ++i) scanf("%d",&d[i]);
                              ^