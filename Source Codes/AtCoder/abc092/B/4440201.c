#include <stdio.h>

int main(void){
    
    int n,d,x,sum;
    sum=0;
    scanf("%d %d %d",&n,&d,&x);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(d%a[i]==0)
            sum+=d/a[i];
        else
            sum+=d/a[i]+1;
    }
    printf("%d\n",x+sum);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n,&d,&x);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^