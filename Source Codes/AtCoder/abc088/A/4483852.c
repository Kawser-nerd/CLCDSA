#include<stdio.h>

int main (void){
    int a,b,c;
    
    scanf("%d",&a);
    scanf("%d",&b);
    
    if(a%500<=b)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^