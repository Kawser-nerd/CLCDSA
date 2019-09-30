#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int h[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &h[i]);
    }
 
    int conn = 0, cnt = 0;
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < N; i++){
            if(h[i] > 0 && conn == 0){
                conn = 1;
                cnt++;
            }else if(h[i] > 0 && conn == 1){
                conn = 1;
            }else if(h[i] <= 0 && conn == 0){
                conn = 0;
            }else if(h[i] <= 0 && conn == 1){
                conn = 0;
            }
            h[i]--;
        }
        conn = 0;
    }
    printf("%d", cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &h[i]);
         ^