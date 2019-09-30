#include <stdio.h>
typedef long long int llint;
 
llint ans = 0;
 
void knapsack(llint W, llint V, llint w[], llint v[], int s, int n)
{
    int i;
    llint rem = W;
    llint sum = V;
    double rsum = 0;
    int rflag = 0;
 
    if(W < 0) {
        return;
    }
    if(s == n) {
        if(sum > ans) {
            ans = sum;
        }
        return;
    }
 
    for(i = s; i < n; i++) {
 
        if(rem == 0) break;
        if(w[i] <= rem) {
            sum += v[i];
            rem -= w[i];
        } else {
            rsum = sum + (double)v[i]*rem/w[i];
            rflag = 1;
            break;
        }
    }
 
    if(rflag) {
        if(rsum > ans) {
            knapsack(W, V, w, v, s+1, n);
            knapsack(W-w[s],V+v[s], w, v, s+1, n);
        } else return;
    } else {
        if(sum > ans) {
            ans = sum;
        }
        return;
    }
}
 
int main()
{
    int i, j;
    int N, W;
    llint t1, w[200];
    llint t2, v[200];
 
    scanf("%d %d", &N, &W);
    for(i = 0; i < N; i++) {
        scanf("%lld %lld", &(v[i]), &(w[i]));
        for(j = i; j-1 >= 0; j--) {
            if((double)v[j]/w[j] > (double)v[j-1]/w[j-1]) {
                t1 = w[j];
                w[j] = w[j-1];
                w[j-1] = t1;
                t2 = v[j];
                v[j] = v[j-1];
                v[j-1] = t2;
            } else break;
        }
    }
 
    knapsack(W, 0, w, v, 0, N);
    printf("%lld\n", ans);
 
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &W);
     ^
./Main.c:59:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld", &(v[i]), &(w[i]));
         ^