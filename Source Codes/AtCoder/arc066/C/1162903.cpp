#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <assert.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;


#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <bitset>
const int maxn = 1e5 + 20;
LL perfixSum[maxn], absSum[maxn];
vector<int>pos;
void cut(LL &val, int pos1, int pos2) {
    if (pos1 > pos2) return;
    val -= absSum[pos2] - absSum[pos1 - 1];
}
void work() {
    int n;
    scanf("%d", &n);
    int val;
    scanf("%d", &val);
    perfixSum[1] = val;
    absSum[1] = val;
    for (int i = 2; i <= n; ++i) {
        int val;
        char op;
        cin >> op;
        scanf("%d", &val);
        if (op == '+') {
            perfixSum[i] = perfixSum[i - 1] + val;
        } else {
            perfixSum[i] = perfixSum[i - 1] - val;
            pos.push_back(i);
        }
        absSum[i] = absSum[i - 1] + val;
    }
    LL ans = perfixSum[n];
    for (int i = 0; i <= (int)pos.size() - 2; ++i) {
        int p1 = pos[i], p2 = pos[i + 1];
        LL tans = absSum[n] - absSum[p2 - 1];
        tans += perfixSum[p1];
        cut(tans, p1 + 1, p2 - 1);
        ans = max(ans, tans);
    }
    cout << ans << endl;
}

int main() {
#ifdef local
    freopen("data.txt", "r", stdin);
//    freopen("data.txt", "w", stdout);
#endif
//    int val;
//    scanf("%d", &val);
//    cout << val << endl;
    work();
    return 0;
}