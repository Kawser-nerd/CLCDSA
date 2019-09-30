#include <stdio.h>

int main(){
    int a,b,c,ans;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b) a+=b,b=a-b,a-=b;
    if(c<a) ans=abs(b-a)+abs(a-c);
    else if(c>b) ans=abs(c-b)+abs(b-a);
    else ans=abs(b-c)+abs(c-a);
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:17: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if(c<a) ans=abs(b-a)+abs(a-c);
                 ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&c);
     ^