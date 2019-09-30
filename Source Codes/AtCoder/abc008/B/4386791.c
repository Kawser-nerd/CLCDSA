#include <stdio.h>
#include <string.h>
#define N_max 51

int main(int argc, char const *argv[]) {
    // ??
    int N;
    char S[N_max][N_max];
    int count[N_max] = {0};
    // ??
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%s", S[i] );
    }
    // ??
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if(strcmp(S[i],S[j])==0){
                count[i]++;
            }
        }
    }
    // ??
    int max=0, i_max;
    for (size_t i = 0; i < N; i++) {
        if (count[i] > max) {
            max = count[i];
            i_max = i;
        }
    }
    // ??
    printf("%s\n", S[i_max] );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", S[i] );
         ^