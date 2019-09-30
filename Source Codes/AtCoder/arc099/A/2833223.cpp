#include <stdio.h>
#include <algorithm>
const int maxn = 1e5+10;
using namespace std;
int a[maxn], n, k, mi = 1e9, l, r, ans = 1e9;
int check(int x){
    if(x%(k-1) == 0) return x/(k-1);
    return x/(k-1)+1;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        mi = min(mi, a[i]);
    }
    for(int i=0;i<n;i++){
        if(mi == a[i]){
            l = i;
            r = n-1-i;
            break;
        }
    }
    ans = min(ans, check(l)+check(r));
    for(int i=1;i<=min(l, k-1);i++){
        ans = min(ans, check(l-i)+check(r-(k-1-i))+1);
    }
    printf("%d\n", ans);
    return 0;
}