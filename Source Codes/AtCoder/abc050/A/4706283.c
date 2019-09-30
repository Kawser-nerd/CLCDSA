#include<stdio.h>
int main(){
    int a,b;
    char op;
    scanf("%d %c %d",&a,&op,&b);
    switch(op){
        case '+':printf("%d\n",a+b);
                 break;
        case '-':printf("%d\n",a-b);
                 break;
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %c %d",&a,&op,&b);
     ^