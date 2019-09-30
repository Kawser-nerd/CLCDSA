#include <stdio.h>
#include <math.h>

#define rep(i, n) for(int i = 0; i < n; i++)
#define in_arr(type, a, n) for(int i = 0; i < n; i++) scanf(type, &((a)[i]));
#define ll long long int

int sum_digit(ll a);

int main(){
    ll a, max = 0;
    scanf("%lld", &a);
    if(a < 10){
        printf("1");
        return 0;
    }
    for(ll i = (int)sqrt(a); i > 9; i--){
        if(a % i == 0) {
            printf("%d", sum_digit(a / i));
            return 0;
        }
    }
    
    printf("%d", sum_digit(a));
    return 0;
}

int sum_digit(ll a){
    int ret = 0;
    while(a > 0){
        ret++;
        a /= 10;
    }
    return ret;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a);
     ^