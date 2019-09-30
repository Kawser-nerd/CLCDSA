#include <stdio.h>
#define MAX 200


 //??????????A>B,??0???A!=B &&N==1 ??0???A==B???1?
//??????????????
//????((N-1)B+A)+1-((N-1)A+B)=(B-A)(N-2)+1
int main(){
    int n,a,b;

    scanf("%d %d %d",&n,&a,&b);
    if(a>b || ((a!=b)&&n==1)){
        printf("0");
        return 0;
    }
    if(a==b){
        printf("1");
        return 0;
    }
    printf("%lld",(long long)(b-a)*(n-2)+1);
    return 0;
        
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n,&a,&b);
     ^