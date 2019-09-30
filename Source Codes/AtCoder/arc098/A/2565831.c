#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    char S[N];
    scanf("%s", S);

    int c = 0, m = 0, mi = 0;

    for(int i = 0; i < N; i++) {
        switch(S[i]) {
            case 'E':
                c++;
                break;
            case 'W':
                c--;
                break;
        }
        
        if(c > m) {
            m = c;
            mi = i;
        }
    }

    int ans = 0;

    for(int i = 0; i < mi; i++) {
        if (S[i] == 'W') {
            ans++;
        }
    }

    for(int i = mi + 1; i < N; i++) {
        if (S[i] == 'E') {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^