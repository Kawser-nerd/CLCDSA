#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):-(a))
int main(){
  char a[12];
  scanf("%s",a);
  int l=strlen(a);
  int ans=999,num,i;
  for(i=0;i<l-2;i++){
    num=0;
    num+=((int)a[i]-48)*100;
    num+=((int)a[i+1]-48)*10;
    num+=(int)a[i+2]-48;
    ans=min(ans,abs(753-num));
  }
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^