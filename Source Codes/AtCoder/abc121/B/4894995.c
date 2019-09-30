#include<stdio.h>

int main(void)
{
        int n,m,c,r=0, re=0;
        int i, j;
        int nn[1000], mm[1000];

        scanf("%d%d%d", &n,&m,&c);

        for(i = 0; i < m; i++) {
                scanf("%d", &mm[i]);
        }
        for(i = 0; i < n; i++) {
                r = 0;
                for(j = 0; j < m; j++) {
                        scanf("%d", &nn[j]);
                        r += nn[j]*mm[j];
                }
                r += c;
                if(r > 0) {
                        re++;
                }
        }
        printf("%d",re);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &n,&m,&c);
         ^
./Main.c:12:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d", &mm[i]);
                 ^
./Main.c:17:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                         scanf("%d", &nn[j]);
                         ^