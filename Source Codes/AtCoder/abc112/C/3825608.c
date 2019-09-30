#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a,b) (a>b?a:b)
int main()
{
    int n, i, j;
    int x[100],y[100],h[100];
    int X, Y, H, max=0;

    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d",&x[i],&y[i],&h[i]);
        max = MAX(max, h[i]);
    }

    for(X=0; X<101; X++) {
        for(Y=0; Y<101; Y++) {
            for(H=max; H<max+201; H++) {
                int flag = 1;
                for(i=0; i<n; i++) {
                    if(h[i] != MAX(0, H-abs(X-x[i])-abs(Y-y[i])) ) {
                        flag = 0;
                        break;
                    }
                }
                if(flag==1) {
                    printf("%d %d %d",X, Y, H);
                }
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&x[i],&y[i],&h[i]);
         ^