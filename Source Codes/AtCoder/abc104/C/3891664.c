// copied and pasted by #2956807(FlatHarvest)
#include <stdio.h>
#include <math.h>

int main()
{
    int D, G;
    int p[10], c[10], s[10], N;
    int max, sum, n, min;
    int i, j;
    scanf("%d %d",&D, &G);

    for(i=0; i<D; i++) {
        scanf("%d %d",&p[i], &c[i]);
        s[i] = 100*(i+1)*p[i] + c[i];
        N += p[i];
    }

    for(i=0; i<(1<<D); i++) {
        sum = n = 0;
        for(j=0; j<D; j++) {
            if(i & (1<<j)) {
                sum += s[j];
                n += p[j];
            } else {
                max = j;
            }
        }
        min = N;
        if(G-sum<=0 && n<N)
            N = n;
        if(G-sum>0) {
            for(j=0; j<D; j++) {
                if(!(i&(1<<j))) {
                    int k = ceil((G-sum)/100./(j+1));
                    if(k<min && k<p[j]) {
                        min = k;
                    }
                }
            }
        }
        if(min<N && n+min<N) {
            N = n + min;
        }
    }
    printf("%d",N);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&D, &G);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&p[i], &c[i]);
         ^