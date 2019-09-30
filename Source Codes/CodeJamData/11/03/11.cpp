#include <iostream>
using namespace std;
int main() {
    int tt = 0;
    int T; scanf("%d",&T); while (T--) {tt++;
        int N; scanf("%d",&N);
        int small = 10000000, tot = 0, ex = 0;
        for (int i=0; i<N; i++) {
            int next; scanf("%d",&next);
            small<?=next;
            tot += next;
            ex ^= next;
        }
        printf("Case #%d: ",tt);
        if (ex==0) printf("%d\n",tot-small);
        else printf("NO\n");
    }
}
