#include<stdio.h>
int main(){
    int a,b,av,r,nt;
    scanf("%d %d",&a,&b);
    av=(a+b)/2;
    if((a+b)%2!=0){
        nt=av+1;
        printf("%d\n",nt);
    }
    else printf("%d\n",av);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^