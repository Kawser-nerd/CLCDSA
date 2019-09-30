#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 1000000;
char s[202];
int a[102][102], n;

int solve(char c) {
    memset(a, 0, sizeof(a));
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(s[i] == c) {
            a[0][i] = 1; cnt ++;
        }
    }
    if(cnt == 0) return INF;

    for(int t = 0; t <= n-1; t ++) {
        int ok = 1;
        for(int i=1;i<=n-t;i++) {
            if(a[t][i] == 0) {
                ok = 0;
            } 
        }
        if(ok) return t;

        for(int i = n-t-1; i >= 1; i--) {
            if(a[t][i+1] || a[t][i]) {
                a[t+1][i] = 1;
            }
        }
    }
}
int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    int ans = INF;
    for(int c = 'a'; c <= 'z'; c++) {
        ans = min(ans, solve((char)c));
    }
    cout << ans << endl;
} ./Main.cpp:34:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.