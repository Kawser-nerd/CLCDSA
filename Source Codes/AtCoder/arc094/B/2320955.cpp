#include <stdio.h>
#include <math.h>

int calc_max_sum(long a, long b){
    long long inte = sqrt(a * b);
    if((inte + 1) * inte < a * b){
        return inte * 2 + 1;
    }else if(inte * inte <= a * b){
        return inte * 2;
    }
}

bool is_square_number(long s){
    long inte = long(sqrt(s));
    if(inte * inte == s){
        return true;
    }else{
        return false;
    }
}

void answer(long long a, long long b){
    long long ans = calc_max_sum(a, b) - 1;

    ans -= 1;

    if(is_square_number(a * b)){
        ans -= 1;
        if (a == b){
            ans = (a - 1) * 2;
        }
    }


    printf("%lld\n", ans);
}


int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        long long a, b;
        scanf("%lld", &a);
        scanf("%lld", &b);
        answer(a, b);
    }
} ./Main.cpp:11:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.