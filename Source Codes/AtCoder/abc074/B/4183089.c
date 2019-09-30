#include <stdio.h>
#include <string.h>
#include <math.h>
int abs(int i){
        return i>0 ? i : i * -1;
}
int min(int i,int j ){
        return i>j ? j : i;
}
int main(void){
        int N;
        int K;
        int ans = 0;
        scanf("%d", &N);
        scanf("%d", &K);
        int L[N];
        for (int i = 0; i < N; i++) {
                scanf("%d", &L[i]);
                ans +=  2 *  min(abs(L[i]-K),abs(L[i]-0));
        }
        printf("%d\n",ans);

        return 0;

} ./Main.c: In function ‘main’:
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &N);
         ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &K);
         ^
./Main.c:18:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d", &L[i]);
                 ^