#include <stdio.h>
int main(void){
    int N, T;
    scanf("%d %d", &N, &T);
    int c;
    int t;
    int min = 1001;
    for (int i = 0; i < N; i++){
        scanf("%d", &c);
        scanf("%d", &t);
        if ((t <= T) && (min > c)) {
            min = c;
        }
    }
    if(min == 1001) printf("%s\n", "TLE");
    else printf("%d\n", min);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &T);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &c);
         ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &t);
         ^