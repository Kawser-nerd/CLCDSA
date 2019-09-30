#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int sum = 0;
    if(a<=b&&a<=c){
        if(b<=c)sum = a+b;
        else sum = a+c;
    }
    else if(b<=a&&b<=c){
        if(a<=c)sum = a+b;
        else sum = b+c;
    }else{
        if(a<=b)sum = a+c;
        else sum = b+c;
    }
    printf("%d\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^