#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MK = 100005;

const int N = 1005;

int b;

long long n, t[N];

long long cal(long long n) {
    long long ret = 0;
    for (int i = 0; i < b; ++i) {
        ret += (n + t[i] - 1) / t[i];
    }
    return ret;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        cin >> b >> n;
        for (int i = 0; i < b; ++i) {
            cin >> t[i];
        }
        long long l = 0, r = n * MK + 1;
        while (l < r) {
            long long mid = l + r >> 1;
            if (cal(mid) < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int last = cal(l - 1), ans = 0;
        for (int i = 0; i < b; ++i) {
            if ((l - 1) % t[i] == 0) {
                ++last;
                if (last == n) {
                    ans = i + 1;
                }
            }
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
