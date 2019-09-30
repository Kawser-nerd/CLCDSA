#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int main(void)
{
    int n, a[MAX_N], b[MAX_N], c[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        c[i] = a[i];
    }
    sort(c, c + n);
    int prev = -1, p = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != prev) {
            b[p++] = c[i];
            prev = c[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (lower_bound(b, b + p, a[i]) - b) << endl;
    }
    return 0;
}