#include <stdio.h>
int main(void){
    int a,b,ans;
    scanf("%d%d",&a,&b);
    ans=a-b;
    ans=fmax(ans,900+a%100-b);
    ans=fmax(ans,a/100*100+90+a%10-b);
    ans=fmax(ans,a/10*10+9-b);
    ans=fmax(ans,a-100-b%100);
    ans=fmax(ans,a-b/100*100-b%10);
    ans=fmax(ans,a-b/10*10);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: implicit declaration of function ‘fmax’ [-Wimplicit-function-declaration]
     ans=fmax(ans,900+a%100-b);
         ^
./Main.c:6:9: warning: incompatible implicit declaration of built-in function ‘fmax’
./Main.c:6:9: note: include ‘<math.h>’ or provide a declaration of ‘fmax’
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^