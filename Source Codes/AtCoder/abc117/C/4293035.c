#include<stdio.h>
#include<stdlib.h>

int cmp(const int *a,const int *b){
  return *a-*b;
}
int main(){
  int n,m,x[100000],y[100000],i,j,t,sum=0;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",&x[i]);
  }
  qsort(x,m,sizeof(int),cmp);
  for(i=0;i<m-1;i++){
    y[i]=x[i+1]-x[i];
  }
  qsort(y,m-1,sizeof(int),cmp);
  for(i=0;i<m-n;i++){
    sum+=y[i];
  }
  printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:13:25: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(x,m,sizeof(int),cmp);
                         ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:17:27: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(y,m-1,sizeof(int),cmp);
                           ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute...