#include <stdio.h>
int main(void){
    int n,a,b,count=0,sum=0,i;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++){
        if(a<=b) sum+=a;
        else{
            if(count<5){
                sum+=b;
                count++;
            }
            else sum+=a;
        }
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^