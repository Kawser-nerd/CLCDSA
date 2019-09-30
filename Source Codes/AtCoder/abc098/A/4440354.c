#include <stdio.h>

int main(){
    
    int a, b;
    scanf("%d%d",&a, &b);
    int sum, dif, pro;
    sum = a+b;
    dif = a-b;
    pro = a*b;
    if(sum > dif){
        if(sum > pro){
            printf("%d\n",sum);
        }else{
            printf("%d\n",pro);
        }
    }else{
        if(dif > pro){
            printf("%d\n",dif);
        }else{
            printf("%d\n",pro);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a, &b);
     ^