#include <bits/stdc++.h>

using namespace std;

pair<int, char> p[30];

void Solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = 'A' + i;
    }
    sort(p, p + n);
    reverse(p, p + n);
    int sum = 0;
    for (int i = 1; i < n; ++i) sum += p[i].first;
    int sz = n;
    while (sum > p[0].first) {
        printf("%c ", p[sz - 1].second);
        p[sz - 1].first--;
        if (p[sz - 1].first == 0) --sz;
        --sum;
    }
    while (sum > 0) {
        printf("%c%c ", p[0].second, p[sz - 1].second);
        p[sz - 1].first--;
        if (p[sz - 1].first == 0) --sz;
        --sum;
    }
    printf("\n");
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        Solve();
    }
}
