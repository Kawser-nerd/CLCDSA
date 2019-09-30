#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int num;
  long long tal;
} memo;

int cmp(const void *p1, const void *p2){
  return ((memo*)p2)->tal - ((memo*)p1)->tal;
}



int main(){
  int n;
  scanf("%d", &n);

  memo a[n];
  int i;
  for(i=0;i<n;i++){
    a[i].num = i;
    scanf("%lld", &a[i].tal);
  }
  qsort(a, n, sizeof(memo), cmp);
  for(i=0;i<n;i++) printf("%d\n", a[i].num+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a[i].tal);
     ^