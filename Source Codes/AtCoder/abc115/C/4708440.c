#include <stdio.h>
#include <stdlib.h>
int cp(const int*a,const int*b){return *a-*b;}
int main(void){
int n,k,h[101000],i,j,s;
scanf("%d %d",&n,&k);
for(i=0;i<n;i++) scanf("%d",&h[i]);
qsort(h,n,sizeof(int),cp);
s=h[k-1]-h[0];
for(i=k;i<n;i++)if(s>h[i]-h[i-k+1])s=h[i]-h[i-k+1];
printf("%d",s);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:23: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
 qsort(h,n,sizeof(int),cp);
                       ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&n,&k);
 ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i=0;i<n;i++) scanf("%d",&h[i]);
                  ^