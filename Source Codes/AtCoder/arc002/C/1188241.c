#include <stdio.h>

int num_input(const char *c, const char L[3], const char R[3]) {
    int res=0;
    for (int i=0; c[i]; ++res) {
        if (
                (c[i] == L[0] && c[i+1] == L[1]) ||
                (c[i] == R[0] && c[i+1] == R[1])
        ) {
            i += 2;
            continue;
        }

        ++i;
    }

    return res;
}

const char S[16][3]={
    "AA", "AB", "AX", "AY",
    "BA", "BB", "BX", "BY",
    "XA", "XB", "XX", "XY",
    "YA", "YB", "YX", "YY"
};

int main() {
    int N;
    char c[1024]={'\0'};

    scanf("%d %s", &N, c);

    int res=1024;
    for (int i=0; i<16; ++i)
        for (int j=i+1; j<16; ++j) {
            int tmp=num_input(c, S[i], S[j]);
            if (res > tmp)
                res = tmp;
        }

    printf("%d\n", res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %s", &N, c);
     ^