#include <stdio.h>
int main(void){
    int a,b,c,k,sum,i;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    sum=a+b+c;
    for(i=0;i<k;i++){
        if(sum+a>=sum+b && sum+a>=sum+c){
            sum+=a;
            a*=2;
        }
        else if(sum+b>=sum+c){
            sum+=b;
            b*=2;
        }
        else{
            sum+=c;
            c*=2;
        }
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&k);
     ^