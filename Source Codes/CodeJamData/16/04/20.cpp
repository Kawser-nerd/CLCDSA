#include <cstdio>
#include<iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

long long k, c, s;

void read() {
    cin>>k>>c>>s;
}

void solve() {
    if (c * s >= k) {
        int prnt = 0;
        for (int i = 0; i < k; i += c) {
            long long idx = 0;
            for (int j = i; j < i + c; j++) {
                idx = idx * k;
                if (j < k) idx += j;
            }
            if (prnt) printf( " ");
            prnt = 1;
            printf ("%lld", idx+1);
        }
        printf ("\n");
    } else {
        printf ("IMPOSSIBLE\n");
    }
}

int main() {
    int cases;

    cin>>cases;
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

