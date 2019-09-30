#include<stdio.h>
int main(){
    int child,adult,num,sale,small,big,sum = 0;
    scanf("%d%d%d%d%d%d",&child,&adult,&sale,&num,&small,&big);
    if(small+big >= num){
        sum = child*small+adult*big-sale*(small+big);
    }else{
        sum = child*small+adult*big;
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&child,&adult,&sale,&num,&small,&big);
     ^