#include <stdio.h>
 
int main(){
    int a[100];
    int count,sum,i,n;

    scanf("%d",&n);
    sum = 0;
    count = 0;
    for(i = 0; i < n; i++){
        scanf("%d",a+i);
        sum += a[i];
        if(a[i] != 0){
            count++;
        }
    }
    if(sum % count == 0){
        printf("%d\n",sum/count);
    }
    else{
        printf("%d\n",(sum/count)+1);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",a+i);
         ^