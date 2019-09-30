#include <stdio.h>
int main(void){
    int n,a,b,i,j,sum=0,ketasum;
    scanf("%d%d%d",&n,&a,&b);
    for(i=1;i<=n;i++){
        j=i;
        ketasum=0;
        while(j!=0){
            ketasum+=j%10;
            j/=10;
        }
        if(ketasum>=a && ketasum<=b) sum+=i;
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^