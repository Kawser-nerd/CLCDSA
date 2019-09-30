# include <stdio.h>

int main(){
    int N;

    scanf("%d", &N);

    int ans = 0;
    int ct;
    for (int i = 105; i <= N; i++){
        ct = 2;
        if (i % 2 == 0) continue;
        else{
            for (int j = 2; j < i; j++){
                if (i % j == 0) ct++;
                if (ct > 8) break;
            }
        }
        if (ct == 8) ans++;
    }

    printf("%d", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^