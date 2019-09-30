#include <stdio.h>

long double testcase() {
    int K, L, S;
    scanf("%d%d%d", &K, &L, &S);

    char monkey[K + 1];
    char target[L + 1];
    scanf("%s%s", monkey, target);

    for(int i = 0; i < L; ++i) {
        int count = 0;
        for(int j = 0; j < K; ++j)
            count += monkey[j] == target[i];
        if(count == 0)
            return 0;
    }

    int pref[L + 2];
    int bord = 0;
    pref[1] = bord;
    for(int i = 1; i < L; ++i) {
        while(bord > 0 && target[bord] != target[i])
            bord = pref[bord];
        if(target[bord] == target[i])
            ++bord;
        pref[i + 1] = bord;
    }

    int needed = 1 + (S - L) / (L - pref[L]);

    long double prob = 1;
    for(int i = 0; i < L; ++i) {
        int count = 0;
        for(int j = 0; j < K; ++j)
            if(monkey[j] == target[i])
                count++;
        prob *= (long double) count / K;
    }

    return needed - (S - L + 1) * prob;
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; ++i) {
        printf("Case #%d: %.8Lf\n", i, testcase());
    }
}
