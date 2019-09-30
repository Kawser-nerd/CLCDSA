#include<stdio.h>
int main(){
    int a,b,tmp,c = 0;
    scanf("%d%d",&a,&b);
    tmp = a%b;
    if(tmp != 0){
        c = b-tmp;
    }
    printf("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^