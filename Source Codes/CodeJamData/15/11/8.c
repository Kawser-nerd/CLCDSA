#include<stdio.h>

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int n, m[1000], i, max = 0, sum = 0, ded = 0;
        scanf("%d", &n);
        for (i = 0 ; i < n ; ++i)
            scanf("%d", m + i);
        for (i = 1 ; i < n ; ++i){
            if (m[i - 1] > m[i]){
                if (m[i - 1] - m[i] > max)
                    max = m[i - 1] - m[i];
                sum += m[i - 1] - m[i];
            }
        }
        if (max > 0){
            for (i = 0 ; i < n - 1 ; ++i)
                if (m[i] < max)
                    ded += max - m[i];
        }
        printf("Case #%d: %d %d\n", u, sum, max * (n - 1) - ded);
    }
    return 0;
}
