#include <stdio.h>
#define MAX_LEVEL 50

/*
???L????????
X_0 = 1
X_L = 2*X_L-1 + 3
X_L = 4*2^L - 3
???L??????????
X_0 = 1
P_L = 2*P_L-1 + 1
P_L = 2*2^L - 1
*/

typedef unsigned long long ull;
typedef struct {
    ull layer_num;
    ull patty_num;
} hamburger_data;


hamburger_data hamburger[MAX_LEVEL + 1];


void init_hamburger(int level) {
    if(level == 0) {
        hamburger[level].layer_num = 1;
        hamburger[level].patty_num = 1;
        return;
    }
    init_hamburger(level - 1);
    hamburger[level].layer_num = 2 * hamburger[level - 1].layer_num + 3;
    hamburger[level].patty_num = 2 * hamburger[level - 1].patty_num + 1;
}


hamburger_data eat_patty(int level, hamburger_data ret) {
    if(ret.layer_num == 0) {
        return ret;
    }
    if(ret.layer_num >= hamburger[level].layer_num) {
        ret.layer_num -= hamburger[level].layer_num;
        ret.patty_num += hamburger[level].patty_num;
        return ret;
    }
    ret.layer_num -= 1;

    ret = eat_patty(level-1, ret);

    if(ret.layer_num == 0) {
        return ret;
    }
    ret.layer_num -= 1;
    ret.patty_num += 1;

    ret = eat_patty(level-1, ret);

    if(ret.layer_num == 0) {
        return ret;
    }
    ret.layer_num -= 1;

    return ret;
}

int main() {
    int N;
    ull X;
    scanf("%d %lld", &N, &X);
    hamburger_data ret = {X, 0};
    init_hamburger(N);
    ret = eat_patty(N, ret);
    printf("%lld\n", ret.patty_num);
} ./Main.c: In function ‘main’:
./Main.c:69:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %lld", &N, &X);
     ^