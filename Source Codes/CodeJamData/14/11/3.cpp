#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int n, k;
long long a[155], b[155];
map<long long, int> mp;

long long scn() {
    long long ans = 0;
    char buf[155];
    scanf("%s", buf);
    for (int i = 0; i < k; i++) {
        ans = ans * 2 + (buf[i] - '0');
    }
    
    return ans;
}

int cnt(long long a) {
    int c = 0;
    while (a) {
        if (a & 1) ++ c;
        a /= 2;
    }
    return c;
}

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        a[i] = scn();
    }
    for (int i = 0; i < n; i++) {
        b[i] = scn();
    }
}

void solve() {
    mp.clear();
    int ans = 200;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[ a[i] ^ b[j] ] ++;
        }
    }
    
    for (map<long long,int> ::iterator it = mp.begin(); it != mp.end(); it++) {
        if ((*it).second == n) {
            if (cnt((*it).first) < ans) {
                ans = cnt((*it).first);
            }
        }
    }
    
    if (ans == 200) {
        printf ("NOT POSSIBLE\n");
    } else {
        printf ("%d\n", ans);
    }
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
