#include<stdio.h>
#include<stdlib.h>

int cmp(const int *a,const int *b){
  return *b-*a;
}
int main(){
  int k,n,l[50],i,sum=0;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++) scanf("%d",&l[i]);
  qsort(l,n,sizeof(int),cmp);
  for(i=0;i<k;i++) sum+=l[i];
  printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:11:25: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(l,n,sizeof(int),cmp);
                         ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",&l[i]);
                    ^