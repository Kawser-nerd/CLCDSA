#include<stdio.h>

int main(){
    int i,N;
    int count=0;
    int a[1000]={};
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<N;i++){
        if(a[i]==a[i+1]){
            if(a[i]+a[i+1]<10000){
                a[i+1]=a[i]+a[i+2];
                count++;
            }
            else{
                a[i+1]=1;
                count++;
            }
        }
    }
    
    printf("%d",count);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^