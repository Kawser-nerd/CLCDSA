#include <stdlib.h>
#include <stdio.h>

int main()
{   int a,b,c,k,s,t;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
    int ans=a*s+b*t;
    if(s+t>=k){
        ans-=(s+t)*c;
    }
    printf("%d\n",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
     ^