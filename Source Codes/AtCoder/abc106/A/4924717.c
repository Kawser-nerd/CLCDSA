#include<stdio.h>

int main(void){
	int a,b;
    int ans;
    scanf("%d",&a);
    scanf("%d",&b);
    ans=(a-1)*(b-1);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^