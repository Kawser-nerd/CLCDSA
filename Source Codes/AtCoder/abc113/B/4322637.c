#include <stdio.h>
#include <math.h>

int main(){
    int N, T, A;
    scanf("%d%d%d", &N, &T, &A);
    int H[N], index;
    float min = 1000, dif;
    for(int i = 0; i < N; i++){
        scanf("%d", &H[i]);
        dif = fabs(T - H[i]*0.006 - A);
        if(dif < min){
            min = dif;
            index = i + 1;
        }
    }
    printf("%d", index);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &N, &T, &A);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &H[i]);
         ^