#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b){
  return *b-*a;
}
int main(){
  int n,a[334000],i;
  scanf("%d",&n);
  for(i=0;i<3*n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,3*n,4,cmp);
  long long ans;
  for(i=1;i<=n*2;i+=2){
    ans+=a[i];
  }
  printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:17: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(a,3*n,4,cmp);
                 ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^