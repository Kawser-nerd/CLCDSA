#include<stdio.h>

 


int main(void){
    int k,s,res=0;
    scanf("%d%d",&k,&s);
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
                if(0<=s-i-j && s-i-j<=k){
                        res++;
                }
            
            }
        }
    

    printf("%d",res);
    return 0;


} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&s);
     ^