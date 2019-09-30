#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int red,blue;
    red = b-a;
    if(red<0) red+=10;
    blue = a-b;
    if(blue<0) blue+=10;
    if(red<blue){
        printf("%d\n",red);
    }
    else{
        printf("%d\n",blue);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^