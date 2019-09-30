#include <stdio.h>
int main(void){
int co=0,i,j,k,num1,num0;
scanf("%d %d",&num0,&num1);
for(i=0;i<=num1/10000;i++){
    for(j=0;j<=(num1-i*10000)/5000;j++){
        if(i+j>num0||i*10000+j*5000>num1)break;
        for(k=0;k<=(num1-i*10000-j*5000)/1000;k++){
            if(i+j+k>num0||i*10000+j*5000+k*1000>num1)break;
            else if(i+j+k==num0&&i*10000+j*5000+k*1000==num1){
                co=1;
                printf("%d %d %d",i,j,k);
                break;
            }
        }
        if(co==1)break;
    }
    if(co==1)break;
}
if(co==0)printf("-1 -1 -1");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&num0,&num1);
 ^