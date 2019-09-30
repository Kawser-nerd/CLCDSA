#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int h,m,s;
    h = n/3600;
    if(0<=h&&h<=9){
        printf("0%d",h);
    }
    else{
        printf("%d",h);
    }
    m = (n-h*3600)/60;
    if(0<=m&&m<=9){
        printf(":0%d",m);
    }
    else{
        printf(":%d",m);
    }
    s = (n-h*3600-m*60);
    if(0<=s&&s<=9){
        printf(":0%d\n",s);
    }
    else{
        printf(":%d\n",s);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^