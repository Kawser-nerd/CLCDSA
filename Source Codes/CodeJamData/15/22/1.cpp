#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int r, c, n;

void read() {
    cin >> r >> c >> n;  
}

bool check(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

int solve() {
    if (n <= (r * c + 1) / 2) return 0;
    int ans = INF;
    int N = n;
    for (int type = 0; type < 2; type++) {
        n = N;
        n -= (r * c) / 2;
        if (type == 1 && r * c % 2 == 1) n--;
        multiset < int > q;
        for (int i = 0; i < r; i++)
            for (int j = (i + type) % 2; j < c; j += 2) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    cnt += check(x, y);
                }
                q.insert(cnt);
            }
        int res = 0;
        for (; n > 0; n--) {
            assert(!q.empty());
            res += *(q.begin());
            q.erase(q.begin());
        }
        ans = min(ans, res);
    }
    return ans;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            printf("%d\n", solve());
        }
    }
    else {
        stress();
    }

    return 0;
}

