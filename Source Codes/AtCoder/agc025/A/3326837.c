#include<stdio.h>
int plus(int);

int main(void){
    int number, sum, ans=100000;
    scanf("%d", &number);
    for(int i=1; i<number; i++){
        sum=plus(i)+plus(number-i);
        if(sum<ans) ans=sum;
    }
    printf("%d\n", ans);
}

int plus(int n){
    int result=0;
    while(n){
        result+=n%10;
        n/=10;
    }
    return result;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &number);
     ^