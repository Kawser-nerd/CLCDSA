#include <iostream>
using namespace std;
int main() {
    int tt = 0;
    int T; scanf("%d",&T); while (T--) {tt++;
        int N; scanf("%d",&N);
        int ct = 0;
        for (int i=1; i<=N; i++) {
            int next; scanf("%d",&next); if (next!=i) ct++;
        }
        printf("Case #%d: %d\n",tt,ct);
    }
}
