#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if ((a==b||b==c||c==a)&&(a==5||b==5||c==5)&&(a==7||b==7||c==7)&&(a+b+c==17)) {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^