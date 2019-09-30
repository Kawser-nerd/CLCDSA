#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b){
  return *b-*a;
}
int main(){
  int n,k,i,r[111];
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++) scanf("%d",&r[i]);
  qsort(r,n,4,cmp);
  double c=0;
  for(i=k;i>0;i--){
    c=(c+r[i-1])/2;
  }
  printf("%lf",c);
} ./Main.c: In function ‘main’:
./Main.c:10:15: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(r,n,4,cmp);
               ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:9:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",&r[i]);
                    ^