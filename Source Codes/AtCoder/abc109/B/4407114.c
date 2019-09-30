#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  int n,i;
  char w[111][11];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",w[i]);
    if(i>0&&w[i][0]!=w[i-1][strlen(w[i-1])-1]){
      puts("No");
      return 0;
    }
  }
  qsort(w,n,sizeof(w[0]),strcmp);
  for(i=1;i<n;i++){
    if(strcmp(w[i],w[i-1])==0){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:26: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(w,n,sizeof(w[0]),strcmp);
                          ^
In file included from ./Main.c:3:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const char *, const char *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",w[i]);
     ^