#include <stdio.h>
#include <string.h>
#define REP(i, n) for(i = 0; i < n; ++i)
#define FOR(i, a, b) for(i = a; i < b; ++i)

unsigned int pow2(unsigned int k){
    if(k == 0){
        return 1;
    }else{
        return 2 * pow2(k - 1);
    }
}


unsigned long long calc(char S[11], unsigned int len, int op){
    int i;
    unsigned long long ret = 0;
    unsigned long long num = 0;

    REP(i, len){
        num *= 10;
        num += S[i] - '0';

        if(op & 1){
            ret += num;
            num = 0;
        }
        op /= 2;
    }
    //printf("ret:%llu\n", ret);
    return ret;
}

int main(){
    char S[11];
    int num = 1;
    int i;
    scanf("%s", S);
    unsigned int len = strlen(S);
    unsigned long long ANS = 0;

    if(len == 1){
        printf("%c\n", S[0]);
    }else{
        FOR(i, pow2(len - 1), pow2(len)){
            ANS += calc(S, len, i);
        }
        printf("%llu\n", ANS);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^