#include<stdio.h>
#include<math.h>
int main(){
    int x,a,b;
    scanf("%d %d %d",&x,&a,&b);
    if(abs(x-a)<abs(x-b)){
        printf("A\n");
    }
    else{
        printf("B\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:8: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if(abs(x-a)<abs(x-b)){
        ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&x,&a,&b);
     ^