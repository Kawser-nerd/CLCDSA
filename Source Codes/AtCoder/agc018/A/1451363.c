#include <stdio.h>

int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return getGCD(b, a % b);
}

int main(void) {
    int N = 0, K = 0;
    int M = 0, G = 0;
    int i = 0;
    int arr[100000] = {0, };
    
    scanf("%d %d", &N, &K);
    
    for (i=0;i<N;i++) {
        scanf("%d", &arr[i]);
        if (M < arr[i]) {
            M = arr[i];
        }
    }
    
    G = arr[0];
    
    for (i=1;i<N;i++) {
        G = getGCD(G, arr[i]);
    }
    
    if (K <= M && K % G == 0) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &K);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &arr[i]);
         ^