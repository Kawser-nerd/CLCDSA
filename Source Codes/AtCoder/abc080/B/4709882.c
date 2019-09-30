#include<stdio.h>
#include<math.h>

int main(void){
    int n,wa=0;
    scanf("%d",&n);
    int m=n;
    if(m/10==0){
        wa=m%10;
    }else{
        for(;m/10!=0;){
            wa+=m%10;
            m=m/10;
            if(m/10==0){
                wa=wa+m;
            }
        }
    }

    if(n%wa==0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^