#include <stdio.h>
int main(void){
    int n,i,j,a,a8=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        a=0;
        for(j=1;j<=i;j++){
            if(i%j==0) a++;
        }
        if(a==8  && i%2==1) a8++;
    }
    printf("%d\n",a8);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^