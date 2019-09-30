#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(void){
  int n;
  char s[101];
  scanf("%d %s",&n,s);
  int i,j,max=0;
  for(i=1;i<n;i++){
    int count=0;
    for(char c='a';c<='z';c++){
      bool l=false,r=false;
      for(j=0;j<i;j++){
        if(s[j]==c) l=true;
      }
      for(j=i;j<n;j++){
        if(s[j]==c) r=true;
      }
      if(l&&r) count++;
    }
     if(max<count) max=count;
  }
  printf("%d",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %s",&n,s);
   ^