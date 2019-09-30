#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, N;
    int S, E;
    int Sh, Sm, Eh, Em;
    int ans[289] = {0};

    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d%*[-]%d", &S, &E);
        Sh = S/100;  Sm = S%100;
        Eh = E/100;  Em = E%100;
        ans[Sh*12+Sm/5] += 1;
        ans[Eh*12+(Em+4)/5] += -1;
    }
    int flag = 0;
    for(i=0; i<289; i++) {
        if(ans[i]>0) {
            if(!flag) {
                printf("%02d%02d-", i/12, i%12*5);
            }
            flag += ans[i];
        }else if(ans[i]<0) {
            flag += ans[i];
            if(!flag) {
                printf("%02d%02d\n", i/12, i%12*5);
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%*[-]%d", &S, &E);
         ^