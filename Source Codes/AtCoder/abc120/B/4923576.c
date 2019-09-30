#include<stdio.h>
   int main(void)
   {
           int a,b,c,i,j,x,y,k,n=0;
   
           scanf("%d%d%d",&a,&b,&k);
   
           if(b>a){
                   c=b;
                  b=a;
                  a=c;
          }
  
  
          for(i=b;i>0;i--){
                  if((b%i==0)&&(a%i==0)){
                          n=n+1;
                          if(n==k) y=i;
                  }
          }
  
          printf("%d\n",y);
  
          return 0;
  } ./Main.c: In function ‘main’:
./Main.c:6:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
            scanf("%d%d%d",&a,&b,&k);
            ^