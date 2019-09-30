#include <stdio.h>
int main(){
    int n,t;
    scanf("%d",&n);
    scanf("%d",&t);
    int x=t;
    for (int i = 0; i < n-1; ++i)
    {
        scanf("%d",&t);
        if (x>=t)
        {
            x=t;
        }
    }
    printf("%d\n",x);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t);
         ^