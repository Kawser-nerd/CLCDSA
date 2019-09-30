#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int d[N];
    for(int i = 0; i < N; i++) scanf("%d", &d[i]);
    int combi = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(d[i] == d[j] && d[i] > 0){
                d[j] = 0;
                combi++;
            }
        }
    }
    printf("%d", N - combi);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:7:32: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i = 0; i < N; i++) scanf("%d", &d[i]);
                                ^