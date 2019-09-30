#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int n, a[N], ord[N];

bool by_a(int i, int j) {
    return a[i] < a[j];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            ord[i] = i;
        }
        int ans = 0;
        sort(ord, ord + n, by_a);
        for (int i = 0; i < n; ++i) {
            int m = n - i - 1, left = 0;
            for (int j = i + 1; j < n; ++j) {
                if (ord[j] < ord[i]) {
                    ++left;
                }
            }
            ans += min(left, m - left);
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
