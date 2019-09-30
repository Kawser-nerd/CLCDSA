#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int func(int n){
    return n%2==0? n/2:3*n+1;
}

int main(){
    int a,i=0;
    scanf("%d",&a);
    while(a){
        if(a==4 || a==2 || a==1) printf("%d",i+4), a=0;
        else a = func(a), i++;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^