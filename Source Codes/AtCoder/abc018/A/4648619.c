#include<stdio.h>
int main(){
    int a,b,c,num[3] = {0};
    scanf("%d%d%d",&a,&b,&c);

    if(a > b && a > c)num[0] = 1;
    else if(a < b && a < c)num[0] = 3;
    else num[0] = 2;

    if(b > a && b > c)num[1] = 1;
    else if(b < a && b < c)num[1] = 3;
    else num[1] = 2;

    if(c > b && c > a)num[2] = 1;
    else if(c < b && c < a)num[2] = 3;
    else num[2] = 2;
    
    for(int i=0;i<3;i++){
        printf("%d\n",num[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^