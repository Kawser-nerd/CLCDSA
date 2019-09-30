#include <stdio.h>
#include <limits.h>
int main(void){
    long int n, d, j=0, ans=0;
    scanf("%ld%ld", &d, &n);
    if(d==0){
        ans=0;
        while(1){
            if(ans%100 != 0){
                j++;
            }
            if(j==n) break;
            ans++;
        }
    }
    else if(d==1){
        ans=100;
        while(1){
            if(ans%100==0 && ans%10000!=0){
                j++;
            }
            if(j==n) break;
            ans=ans+100;
        }
    }
    else if(d==2){
        ans=10000;
        while(1){
            if(ans%10000==0 && ans%1000000!=0){
                j++;
            }
            if(j==n) break;
            ans=ans+10000;
        }
    }

    printf("%ld\n", ans);
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld", &d, &n);
     ^