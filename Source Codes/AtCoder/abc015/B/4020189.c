#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int c;
    int sum;
    sum = 0;
    c = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",a+i);
        sum += a[i];
        if(a[i] != 0){
            c++;
        }
    }
    if(sum % c == 0){
        printf("%d\n",sum/c);
    }
    else{
        printf("%d\n",(sum/c)+1);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",a+i);
         ^