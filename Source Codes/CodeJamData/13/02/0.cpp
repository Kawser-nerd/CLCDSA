#include <cstdio>
using namespace std;

int t[100][100];

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);

    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            scanf("%d", &t[i][j]);
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int c = t[i][j];
            
            bool ok = true;
            for (int k=0; k<n; ++k) {
                if (t[k][j] > c) {
                    ok = false;
                    break;
                }
            }
            if (ok) continue;

            ok = true;
            for (int k=0; k<m; ++k) {
                if (t[i][k] > c) {
                    ok = false;
                    break;
                }
            }
            
            if (!ok) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    return;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        make();
    }
    return 0;
}
