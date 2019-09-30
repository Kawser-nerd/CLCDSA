#include<stdio.h>
#include<stdlib.h>

int cmpl(const void *p1, const void *p2){
  return *(int*)p2 - *(int*)p1;
}

int cmpr(const void *p1, const void *p2){
  return *(int*)p1 - *(int*)p2;
}

int main(void){
  int n;
  scanf("%d", &n);
  int l[n+1], r[n+1], i;
  for(i=0;i<n;i++) scanf("%d %d", &l[i], &r[i]);
  l[n] = 0;
  r[n] = 0;
  
  qsort(l, n+1, sizeof(int), cmpl);
  qsort(r, n+1, sizeof(int), cmpr);

  int tmp;
  long long ans = 0;
  for(i=0;i<=n;i++){
    tmp = (l[i]-r[i]) * 2;
    if(tmp < 0) break;
    ans += (long long)tmp;
  }

  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d %d", &l[i], &r[i]);
                    ^