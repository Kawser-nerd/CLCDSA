#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    char picked_arare;
    int flag = 0;
    for (int i = 0; i < N;i++){
        scanf("%c",&picked_arare);
        if(picked_arare == 'Y'){
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Three");
    }
    else if (flag == 1){
        printf("Four");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&picked_arare);
         ^