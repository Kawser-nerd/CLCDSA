#include<stdio.h>
 
int main(){
        int n,a,b;
        scanf("%d %d %d", &n,&a,&b);
        int m = a<b ? b : a;
        int l = a<b ? a : b;
 
        if((m-l)%2==0) printf("Alice\n");
        else printf("Borys\n");
        return 0;
 
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &n,&a,&b);
         ^