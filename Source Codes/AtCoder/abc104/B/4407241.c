#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const char *a,const char *b){
  return *a-*b;
}
int main(){
  char s[11];
  scanf("%s",s);
  if(s[0]=='A'&&s[1]>='a'&&s[strlen(s)-1]>='a'){
    qsort(s,strlen(s),sizeof(s[0]),cmp);
    if(s[1]=='C'&&s[2]>='a'){
      puts("AC");
      return 0;
    }
  }
  puts("WA");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:36: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
     qsort(s,strlen(s),sizeof(s[0]),cmp);
                                    ^
In file included from ./Main.c:3:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const char *, const char *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^