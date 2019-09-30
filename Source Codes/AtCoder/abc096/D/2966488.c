#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

bool sosu (int a){
    for (int i=2; i<a; i++){
        if (a%i==0){
            return false ;
        }
    }
    return true;
}

int main(void){
    int n,count=0;
    scanf("%d",&n);
    for (int i=2; i<=55555; i++){
        if (sosu(i)==true && i%5==1){
            printf("%d\n",i);
            count++;
        }
        if (count==n){
            break;
        }
    }    
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^