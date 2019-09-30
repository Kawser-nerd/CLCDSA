#include<stdio.h>

int main(){
    int N;
    int group_number=0;
    scanf("%d",&N);
    group_number = N / 3;
    printf("%d ",group_number);
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^