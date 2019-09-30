#include <stdio.h>
int power(int a){
    int i,s=1;
    if(a==0)
    return(1);
    else
    {for(i=0;i<a;i++)
    s=s*100;
    }
    return("%d",s);
}

int main(void){
    int D,N;
    scanf("%d %d",&D,&N);
   
    if(N==100)
    printf("%d",101*power(D));
    else if(D==0)
    printf("%d",N);
    else if(D==1)
    printf("%d",N*100);
    else if(D==2)
    printf("%d",N*10000);
  
    return(0);
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&D,&N);
     ^