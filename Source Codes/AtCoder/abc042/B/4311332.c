#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  char s[111][111];
  int n,l,i;
  scanf("%d%d",&n,&i);
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  qsort(s,n,sizeof(s[0]),strcmp);
  for(i=0;i<n;i++){
    printf("%s",s[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:12:26: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(s,n,sizeof(s[0]),strcmp);
                          ^
In file included from ./Main.c:3:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const char *, const char *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&i);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^