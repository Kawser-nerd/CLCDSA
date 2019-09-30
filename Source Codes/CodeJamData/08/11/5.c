#include <stdio.h>
#include <stdlib.h>

int compare1(const void* a, const void* b ) {
  int* arg1 = (int*) a;
  int* arg2 = (int*) b;
  if( *arg1 < *arg2 ) return -1;
  else if( *arg1 == *arg2 ) return 0;
  else return 1;
}        

int compare2(const void* a, const void* b ) {
  int* arg1 = (int*) a;
  int* arg2 = (int*) b;
  if( *arg1 < *arg2 ) return 1;
  else if( *arg1 == *arg2 ) return 0;
  else return -1;
}


int main () {
  int t, n, a[1000], b[1000], i, j;
  long long ans = 0;
  j = 1;
  scanf ("%d", &t);
  while (t --) {
    scanf("%d", &n);
    ans = 0;
    for (i = 0; i < n; i ++) {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i ++) {
      scanf("%d", &b[i]);
    }
    qsort(a, n, sizeof(int), compare1);
    qsort(b, n, sizeof(int), compare2);
    for (i = 0; i < n; i ++) {
      ans += (long long)(a[i])*(long long)(b[i]);
    }
    printf("Case #%d: %lld\n", j, ans);
    j ++;
  }
  return 0;
}
