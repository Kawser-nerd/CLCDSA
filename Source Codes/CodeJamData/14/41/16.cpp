#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, size;
        scanf("%d%d", &n, &size);
        vector<int> w;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            w.push_back(a);
        }
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        int i = 0, j = w.size() - 1;
        int ans = 0;
        while (i <= j) {
            if (i == j) {
                ++ans;
                ++i;
            } else {
                if (w[i] + w[j] <= size) {
                    ++ans;
                    ++i, --j;
                } else {
                    ++ans;
                    ++i;
                }
            }
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
