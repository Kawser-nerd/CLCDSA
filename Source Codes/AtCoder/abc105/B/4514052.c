#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    if(n>=18||n%4==0||n%7==0||n==11||n==15)printf("Yes\n");
    else printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^