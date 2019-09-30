#include <stdio.h>

int main(){
    int n,m,N;
    scanf("%d %d %d",&m,&n,&N);
    int now=N;
    while(1){
        if(now-m<0)break;
        else{
            now-=m;
            now+=n;
            N+=n;
        }
    }
    printf("%d\n",N);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&m,&n,&N);
     ^