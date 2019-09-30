#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int mo = 1000002013;

struct T {
    int idx, p;
    bool type;
};

bool operator<(const T &a, const T &b)
{
    if (a.idx != b.idx)
        return a.idx < b.idx;
    else
        return a.type & !b.type;
}

int N, M;

long long cost(long long dis)
{
    return dis * (N * 2 + 1 - dis) / 2 % mo;
}

void work()
{
    cin >> N >> M;
    vector<T> a;
    long long ret = 0;
    for (int i = 1; i <= M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ret = (ret + cost(y - x) * z) % mo;
        T t;
        t.p = z;
        t.idx = x;
        t.type = true;
        a.push_back(t);
        t.idx = y;
        t.type = false;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    map<int, long long> f;
    for (int i = 0; i < a.size(); ++i)
        if (a[i].type)
            f[a[i].idx] += a[i].p;
        else {
            long long p = a[i].p;
            while (p) {
                map<int, long long>::iterator it = f.end();
                --it;
                if (it->second <= p) {
                    ret = (ret - cost(a[i].idx - it->first) * it->second) % mo;
                    p -= it->second;
                    f.erase(it);
                }else {
                    ret = (ret - cost(a[i].idx - it->first) * p) % mo;
                    it->second -= p;
                    p = 0;
                }
            }
        }
    cout << (ret % mo + mo) % mo;
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}
