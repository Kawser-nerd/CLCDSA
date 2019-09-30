#include<stdio.h>

int main(){
    int buff[3];
    int i,j;
    int rank[3]={1,1,1};
    scanf("%d",&buff[0]);
    scanf("%d",&buff[1]);
    scanf("%d",&buff[2]);

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(buff[i]<buff[j]){
                rank[i]++;
            }
        }
    }
    printf("%d\n%d\n%d\n",rank[0],rank[1],rank[2]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&buff[0]);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&buff[1]);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&buff[2]);
     ^