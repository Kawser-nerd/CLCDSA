#include<stdio.h>
#include<stdlib.h>

int cmp(const int *a,const int *b){
  return *a-*b;
}
int main(){
  int n,l[222];
  scanf("%d",&n);
  n*=2;
  for(int i=0;i<n;i++){
    scanf("%d",&l[i]);
  }
  qsort(l,n,4,cmp);
  int sum=0;
  for(int i=0;i<n;i+=2){
    sum+=l[i];
  }
  printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:14:15: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(l,n,4,cmp);
               ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^