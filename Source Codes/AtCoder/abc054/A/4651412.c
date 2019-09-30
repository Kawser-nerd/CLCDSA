#include <stdio.h>
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==1 || b==1){
        if(b!=1) printf("Alice\n");
        else if(a!=1) printf("Bob\n");
        else printf("Draw\n");
        return 0;
    }
    printf("%s\n",a>b?"Alice":(a<b?"Bob":"Draw"));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^