#include <stdio.h>
int main(void){
    // Your code here!
    int a,b,c,k,s,t,g;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
    g = a*s+b*t;
    if(s+t>=k)
        g -= (s+t)*c;
    printf("%d\n",g);    
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
     ^