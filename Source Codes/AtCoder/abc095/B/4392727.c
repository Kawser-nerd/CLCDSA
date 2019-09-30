#include<stdio.h>

int main(void)
{
        int a, b, tmp, ans;
        int i, j;
        scanf("%d%d", &a, &b);
        int m[a];
        for(i=0;i<a;i++){
                scanf("%d", &m[i]);
        }

        for(i=0;i<a;i++){
                for(j=0;j<a;j++){
                        if(m[i]<m[j]){
                                tmp = m[i];
                                m[i] = m[j];
                                m[j] = tmp;
                        }
                }
        }
        tmp = 0;
        for(i=0;i<a;i++){
                tmp = tmp + m[i];
        }

        b = b - tmp;
        ans = (b / m[0]) + a;

        printf("%d\n", ans);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^
./Main.c:10:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d", &m[i]);
                 ^