#include <stdio.h>





int main(void){
    int N;
    scanf("%d",&N);
    if(N==3){printf("2 5 63");return 0;}
    if(N==4){printf("2 5 20 63");return 0;}
    int po=N%8;
    if(po==1)printf("30000 ");
    if(po==2)printf("30000 29994 ");
    if(po==3)printf("30000 29998 29996 ");
    if(po==4)printf("30000 29998 29996 29994 ");
    if(po==5)printf("30000 29991 29997 29998 29996 ");
    if(po==6)printf("30000 29994 29997 29991 29998 29996 ");
    if(po==7)printf("29990 29992 29996 29998 29991 29997 30000 ");
    N-=po;
    for(int i=1;;i++){
        if(i%2==0||i%3==0){printf("%d ",i);N--;}
        if(N<=0)break;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^