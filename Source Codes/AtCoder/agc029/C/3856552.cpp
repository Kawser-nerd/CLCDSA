#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000 + 5;

int n;
int a[N];
pair<int, int> str[N];

bool check(int sigma) {
    int top = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            continue;
        } else {
            for ( ; top; ) {
                if (str[top].first > a[i]) {
                    top--;
                } else {
                    break;
                }
            }
            int ptr = a[i];
            for ( ; ptr > 0; ptr--) {
                if (top && str[top].first == ptr) {
                } else {
                    str[++top] = make_pair(ptr, 0);
                }
                str[top].second++;
                if (str[top].second == sigma) {
                    top--;
                } else {
                    break;
                }
            }
            if (ptr == 0) {
                return false;
            } else {
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}

int main() {
    solve();
    return 0;
}