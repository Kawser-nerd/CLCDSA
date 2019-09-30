#include<stdio.h>

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int b, n, i, j, a[1000];
        long long l, r;
        scanf("%d%d", &b, &n);
        for (i = 0 ; i < b ; ++i)
            scanf("%d", a + i);
        if (n <= b){
            printf("Case #%d: %d\n", u, n);
            continue;
        }
        for (l = 0, r = 100000000000000ll ; l < r - 1 ; ){
            long long sum = b, m = (l + r + 1) / 2;
            for (i = 0 ; i < b ; ++i)
                sum += m / a[i];
            if (sum < n)l = m;
            else r = m;
        }
        long long sum = b;
        int bb[1000] = {}, num = 0;
        for (i = 0 ; i < b ; ++i){
            sum += r / a[i];
            if (r % a[i] == 0)
                bb[num++] = i;
        }
        printf("Case #%d: %d\n", u, bb[n - (sum - num) - 1] + 1);
    }
    return 0;
}
