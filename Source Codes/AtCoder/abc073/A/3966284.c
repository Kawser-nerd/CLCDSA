#include <stdio.h>
int main(void){
    char n[2],a=0;
    scanf("%s",n);
    for(int i=0;i<=1;i++){
        if(n[i]=='9') {a=1;break;}
    }
    if(a==1) printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",n);
     ^