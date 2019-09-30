#include <stdio.h>
int main(void){
int ans;
  int inp;
  scanf("%d",&inp);
  for(ans=0;;ans++){
   if(ans*ans>inp){printf("%d",(ans-1)*(ans-1));break;}
    }
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&inp);
   ^