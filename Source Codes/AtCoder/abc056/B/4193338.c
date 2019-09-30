#include <stdio.h>
int main(){
    int w,a,b;
    scanf("%d %d %d",&w,&a,&b);
    if(b-(a+w)<=0&&a<=b){
        printf("0");
    }else if(a>b){
        printf("%d",a-(b+w));
    }else{
        printf("%d",b-(a+w));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&w,&a,&b);
     ^