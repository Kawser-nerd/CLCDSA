#include <stdio.h>

int main(void)
{
    int N, i;
    char S[200];
    char S_right[3] = {'b', 'a', 'c'};
    char S_left[3] = {'b', 'c', 'a'};

    scanf("%d", &N);
    scanf("%s", S);

    if(!(N%2)) {
        printf("%d\n", -1);
        return 0;
    }

    if(N == 1 && S[0] == 'b') {
        printf("%d\n", 0);
        return 0;
    }

    if(S[N/2] != 'b') {
        printf("%d\n", -1);
        return 0;
    }else {
        for(i=1; i<=N/2; i++) {
            if(S[N/2-i] != S_right[i%3]) {
                printf("%d\n", -1);
                return 0;
            }
            if(S[N/2+i] != S_left[i%3]) {
                printf("%d\n", -1);
                return 0;
            }
        }
    }
    printf("%d\n", N/2);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^