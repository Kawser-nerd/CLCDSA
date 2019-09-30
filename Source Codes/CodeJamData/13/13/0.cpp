#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 12 + 5, maxk = 12 + 5;

int R, N, M, K;
long long p[maxk], jc[maxn];
char a[maxn];

struct Sol {
    string a;
    long long rep;
    map<long long, int> P;
    double check()
    {
        double ret = 1;
        for (int i = 1; i <= K; ++i) {
            map<long long, int>::iterator it = P.find(p[i]);
            if (it == P.end())
                return 0;
            ret *= it->second;
        }
        return ret / rep;
    }
};
vector<Sol> v;

void dfs(int i)
{
    if (i == N) {
        Sol t;
        t.a = string(a);
        //cout << a << endl;
        t.rep = 1;
        for (int j = 0, k = -1; j < N; ++j)
            if (a[j] != a[j + 1]) {
                t.rep *= jc[j - k];
                k = j;
            }
        for (int j = 0; j < (1 << N); ++j) {
            long long pro = 1;
            for (int k = 0; k < N; ++k)
                if (j & (1 << k))
                    pro *= a[k] - '0';
            ++t.P[pro];
        }
        v.push_back(t);
    }else
        for (char j = i > 0 ? a[i - 1] : '2'; j <= '0' + M; ++j) {
            a[i] = j;
            dfs(i + 1);
        }
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d:\n", t1);
        cin >> R >> N >> M >> K;
        jc[0] = 1;
        for (int i = 1; i <= N; ++i)
            jc[i] = jc[i - 1] * i;
        a[N] = '\0';
        dfs(0);
        while (R--) {
            for (int i = 1; i <= K; ++i)
                cin >> p[i];
            double ret = 0;
            int reti = 0;
            for (int i = 0; i < v.size(); ++i) {
                double t = v[i].check();
                if (t > ret) {
                    ret = t;
                    reti = i;
                }
            }
            cout << v[reti].a << endl;
        }
        printf("\n");
    }
    
    return 0;
}
