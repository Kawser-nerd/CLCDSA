#include <stdio.h>
int main(void){
    int a,b,c,r[3]={0},i;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b && b>c){
        r[0]=1;
        r[1]=2;
        r[2]=3;
    }
    else if(a>c && c>b){
        r[0]=1;
        r[1]=3;
        r[2]=2;
    }
    else if(b>a && a>c){
        r[0]=2;
        r[1]=1;
        r[2]=3;
    }
    else if(b>c && c>a){
        r[0]=3;
        r[1]=1;
        r[2]=2;
    }
    else if(c>a && a>b){
        r[0]=2;
        r[1]=3;
        r[2]=1;
    }
    else if(c>b && b>a){
        r[0]=3;
        r[1]=2;
        r[2]=1;
    }
    for(i=0;i<3;i++){
        printf("%d\n",r[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^