#include<stdio.h>
#include<string.h>
int main(){
  char s[100010];
  int n,c=0;
  scanf("%d",&n);
  while(n--){
    scanf(" %s",s);
    if(strcmp(s,"TAKAHASHIKUN")==0)c++;
    if(strcmp(s,"Takahashikun")==0)c++;
    if(strcmp(s,"takahashikun")==0)c++;
    if(strcmp(s,"TAKAHASHIKUN.")==0)c++;
    if(strcmp(s,"Takahashikun.")==0)c++;
    if(strcmp(s,"takahashikun.")==0)c++;
  }
  printf("%d\n",c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %s",s);
     ^