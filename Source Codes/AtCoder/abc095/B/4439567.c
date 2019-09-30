#include <stdio.h>

int main(void){
    
    int n,x,min,sum;
    min=1000;
    sum=0;
    scanf("%d %d",&n,&x);
    int m[n];
    
    for(int i=0; i<n; i++){
        scanf("%d",&m[i]);
        sum+=m[i];
        
        if(min>m[i])
            min=m[i];
    }

    printf("%d",n+(x-sum)/min);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&x);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m[i]);
         ^