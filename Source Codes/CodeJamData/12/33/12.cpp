
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;


int T, n, m;
ll n1[103], n2[103];
int p1[103], p2[103];

ll dp[103][103];

void checkmax(ll& a, ll b) {
    if (b > a) a = b;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    cin >> T;
    
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> n1[i] >> p1[i];
        for (int i = 1; i <= m; ++i)
            cin >> n2[i] >> p2[i];
        
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                ll t = dp[i][j];
                if (i + 1 <= n) checkmax(dp[i + 1][j], t);
                if (j + 1 <= m) checkmax(dp[i][j + 1], t); 
                if (i == 1 && j == 0) {
                    int yy = 0;
                }
                if (i + 1 <= n && j + 1 <= m && p1[i + 1] == p2[j + 1]) {
                    int c = p1[i + 1];
                    int x = i + 1, y = j + 1;
                    ll a = n1[x], b = n2[y];
                    while (x <= n && y <= m) {
                        ll add = min(a, b);
                        t += add;
                        a -= add;
                        b -= add;
                        checkmax(dp[x][y], t);
                        while (a == 0 && x <= n) {
                            ++x;
                            if (p1[x] == c) a += n1[x];
                        }
                        while (b == 0 && y <= m) {
                            ++y;
                            if (p2[y] == c) b += n2[y];
                        }
                    }
                }
              //  cout << dp[i][j] << ' ';
            }   
            //cout << endl;
        }
        
        printf("Case #%d: ", cs);
        cout << dp[n][m] << endl;
        
    }
    //system("pause");
    return 0;
}
/*
1
3
2 2 3
1 3
0

*/
