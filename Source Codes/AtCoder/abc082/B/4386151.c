#include<stdio.h>
#include<string.h>

int cmp1(const char *a,const char *b){
  return *a-*b;
}
int cmp2(const char *a,const char *b){
  return *b-*a;
}
int main(){
  char a[111],b[111];
  scanf("%s%s",a,b);
  qsort(a,strlen(a),sizeof(a[0]),cmp1);
  qsort(b,strlen(b),sizeof(b[0]),cmp2);
  puts(strcmp(a,b)<0?"Yes":"No");
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
   qsort(a,strlen(a),sizeof(a[0]),cmp1);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",a,b);
   ^