/* note - I use dev-cpp which uses %I64d for long longs, not %ll. */

#include <iostream>
#include <cmath>

using namespace std;
long long v1[100000], v2[100000];
int main() {
    int T;scanf("%d",&T); 
    for (int t=1; t<=T; t++) {
        int N; scanf("%d",&N);
        for (int i=0; i<N; i++) {
            scanf("%I64d",&v1[i]);
        }
        for (int i=0; i<N; i++) {
            scanf("%I64d",&v2[i]);
        }
        sort(v1,v1+N);
        sort(v2,v2+N);
        long long ans = 0;
        for (int i=0; i<N; i++) ans+=v1[i]*v2[N-i-1];
        printf("Case #%d: %I64d\n",t,ans);
    }
}
