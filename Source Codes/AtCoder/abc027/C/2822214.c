#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    long long n,x=1,count=0;
    scanf("%lld",&n);
    long long depth=0,d=1;
    for (int i=0; i<n; i++){
        if (n>=d){
            d*=2;
            depth++;
        } else {
            break;
        }
    }
    for (int i=0; i<depth; i++){
        if (x>n){
            break;
        }
        count++;
        if (depth%2==0){
            if (i%2==0){
                x=x*2;
            } else {
                x=x*2+1;
            }
        } else {
            if (i%2==0){
                x=x*2+1;
            } else {
                x=x*2;
            } 
        }
    }
    if (count%2==0){
        printf("Takahashi\n") ;
    } else {
        printf("Aoki\n");
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^