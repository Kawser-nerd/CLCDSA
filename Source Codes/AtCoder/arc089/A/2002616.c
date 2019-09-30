#include <stdio.h>

int kyori(int x1,int y1,int x2,int y2){
    int po1=x1-x2;
    if(po1<0)po1*=-1;
    int po2=y1-y2;
    if(po2<0)po2*=-1;
    return po1+po2;
}

int main(void){
    int N;
    scanf("%d",&N);
    int x=0;
    int y=0;
    int t=0;
    for(int i=0;i<N;i++){
        int X,Y,T;
        scanf("%d %d %d",&T,&X,&Y);
        if(kyori(x,y,X,Y)>T-t||(T-t-kyori(x,y,X,Y))%2==1){printf("No");return 0;}
        else {
            x=X;
            y=Y;
            t=T;
        }
    }
    printf("Yes");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&T,&X,&Y);
         ^