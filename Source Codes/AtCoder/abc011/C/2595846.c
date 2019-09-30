#include <stdio.h>

int main(void)
{
    int N, NG[3], i, count = 0;

    scanf("%d", &N);
    for(i=0; i<3; i++) {
        scanf("%d", &NG[i]);
    }

    if(N == NG[0] || N == NG[1] || N == NG[2]) {
        printf("NO\n");
        return 0;
    }
    while(N>0) {
        count++;
        N -= 3;
        if(N == NG[0] || N == NG[1] || N == NG[2]) {
            N += 1;
            if(N == NG[0] || N == NG[1] || N == NG[2]) {
                N += 1;
                if(N == NG[0] || N == NG[1] || N == NG[2]) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    if(count <= 100)  printf("YES\n");
    else printf("NO\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &NG[i]);
         ^