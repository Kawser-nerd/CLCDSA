#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,r,c,w;
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &test);
    for(int t = 1; t <= test; t++){
        scanf("%d%d%d", &r, &c, &w);
        int ans, x;
        x = c/w;
        ans = (r - 1) * x;
        ans += (x - 1);
        if(c > (w*x)){
            ans += (w + 1);
        }else{
            ans += w;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
