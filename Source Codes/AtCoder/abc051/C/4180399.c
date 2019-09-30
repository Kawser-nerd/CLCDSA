#include<stdio.h>

int main(){
    int sx,sy,tx,ty,i;
    int dx,dy;

    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    dx = tx-sx; dy=ty - sy;

    for(i=0;i<dy;i++){
        printf("U");
    }
    for(i=0;i<dx;i++){
        printf("R");
    }
    for(i=0;i<dy;i++){
        printf("D");
    }
    for(i=0;i<dx+1;i++){
        printf("L");
    }
    for(i=0;i<dy+1;i++){
        printf("U");
    }
    for(i=0;i<dx+1;i++){
        printf("R");
    }
    printf("D");printf("R");
    for(i=0;i<dy+1;i++){
        printf("D");
    }
    for(i=0;i<dx+1;i++){
        printf("L");
    }
    printf("U");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
     ^