#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    if(n<105) printf("%d",0);
    else if(n<135) printf("%d",1);
    else if(n<165) printf("%d",2);
    else if(n<189) printf("%d",3);
    else if(n<195) printf("%d",4);
    else printf("%d",5);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^