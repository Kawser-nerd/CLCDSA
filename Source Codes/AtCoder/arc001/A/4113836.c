#include<stdio.h>

int main(){
    int num, k, l, j,max=0,min=100;
    int count[4]={0};
    char moji[4]={'1','2','3','4'};
    char buff[101];

    scanf("%d",&num);
    scanf("%s",buff);
        for(k=0;k<num;k++){
        for(j=0;j<4;j++){
            if(buff[k]==moji[j]){
                count[j]++;
            }
        }
    }
    for(l=0;l<4;l++){
        if(min>count[l]){
            min = count[l];
        }
        if(max<count[l]){
            max = count[l];
        }
    }
    printf("%d %d\n",max,min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",buff);
     ^