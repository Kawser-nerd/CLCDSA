#include<stdio.h>

int main(){
    int i,j,work;
    int buff[3];

    scanf("%d %d %d",&buff[0],&buff[1],&buff[2]);
    for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            if(buff[i]<buff[j]){
                work = buff[i];
                buff[i] = buff[j];
                buff[j] = work;
            }
        }
    }
    printf("%d\n",buff[1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&buff[0],&buff[1],&buff[2]);
     ^