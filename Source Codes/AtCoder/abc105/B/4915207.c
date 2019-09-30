#include <stdio.h>
int main(void){
   int i,N,cnt=0;
   
   scanf("%d",&N);
   
   for(i=0;i<=N/4;i++){
       if( ((N-4*i)%7) ==0)
       cnt++;
   }
      if(cnt>0)
      printf("Yes");
      else
      printf("No");
      
       return(0);
   } ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&N);
    ^