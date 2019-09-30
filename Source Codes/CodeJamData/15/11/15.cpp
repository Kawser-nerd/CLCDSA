#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, a[N];

int cal1() {
    int ret = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] < a[i]) {
            ret += a[i] - a[i + 1];
        }
    }
    return ret;
}

int cal2() {
    int delta = 0;
    for (int i = 0; i + 1 < n; ++i) {
        delta = max(a[i] - a[i + 1], delta);
    }
    int ret = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ret += min(delta, a[i]);
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        static int id = 0;
        printf("Case #%d: %d %d\n", ++id, cal1(), cal2());
    }
    return 0;
}
