#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b){
  return *a-*b;
}
int main(){
  int a[5],ans;
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  qsort(a,3,4,cmp);
  if(a[0]%2==a[1]%2){
    ans=(a[1]-a[0])/2+a[2]-a[1];
  }
  else {
    ans=(a[2]-a[0])/2+(a[2]-a[1])/2+2;
  }
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:9:15: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(a,3,4,cmp);
               ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a[0],&a[1],&a[2]);
   ^