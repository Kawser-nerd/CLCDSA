#include <stdio.h>
int main (){
int a,b,ans=0,i;
scanf ("%d%d",&a,&b);
  for (i=a;i<b+1;i++){
  if (i/10000 == i%10){
    if ((i-((i/10000)*10000))/1000 == (i-((i/100)*100))/10){
    ans++;
    }
  }
  }
  printf ("%d",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&a,&b);
 ^