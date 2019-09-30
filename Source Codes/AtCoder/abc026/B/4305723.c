#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const int *a,const int *b){
  return *b-*a;
}
int main(){
  int n,r[1000],i,s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  qsort(r,n,sizeof(int),cmp);
  for(i=0;i<n;i++){
    s+=i%2?-r[i]*r[i]:r[i]*r[i];
  }
  printf("%f\n",s*M_PI);
} ./Main.c: In function ‘main’:
./Main.c:14:25: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(r,n,sizeof(int),cmp);
                         ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&r[i]);
     ^