#include <stdio.h>
int main(void){
    int x=0,n,max=0;
    char s[100];
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='I') x+=1;
        else x-=1;
        if(max<x) max=x;
    }
    printf("%d",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^