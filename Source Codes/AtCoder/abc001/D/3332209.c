#include <stdio.h>
int main(void){
    int n,rain[2403]={};
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        int s,e;
        scanf("%d-%d",&s,&e);
        s=s/5*5;
        e=(e+4)/5*5;
        if (e%100==60){
            e+=40;
        }
        for (int j=s; j<=e; j++){
            rain[j]=1;
        }
    }
    for (int i=0; i<=2401; i++){
        if (rain[i]==1 && rain[i-1]!=1){
            if (i>=1000){
                printf("%d-",i);
            } else if (i>=100){
                printf("0%d-",i);
            } else if (i>=10){
                printf("00%d-",i);
            } else {
                printf("000%d-",i);
            }
        }
        if (rain[i]==0 && rain[i-1]==1){
            if (i>=1000){
                printf("%d\n",i-1);
            } else if (i>=100){
                printf("0%d\n",i-1);
            } else if (i>=10){
                printf("00%d\n",i-1);
            } else {
                printf("000%d\n",i-1);
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d-%d",&s,&e);
         ^