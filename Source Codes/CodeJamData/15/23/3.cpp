#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

#define eprintf(...) //fprintf(stderr, __VA_ARGS__)

typedef long long llong;

vector<pair<llong, int> > E;

int hum;

struct human
{
    int d;
    llong m;
    int q;
    int val;
    human(int d, llong m)
    {
        this->d = d;
        this->m = m;
        this->val = 0;
        this->q = 0;
    }
    llong nextTime() const 
    {
        return (360 - d) * m + q * 360 * m;
    }
    void inc()
    {
        q++;
    }
    int nextDelta() const
    {
        return (q == 0) ? -1 : 1;
    }
    friend bool operator <(human a, human b)
    {
        return a.nextTime() < b.nextTime();
    }
};

void add_human(int d, llong m)
{
    E.push_back(make_pair((360 - d) * m, -1));
    for (int i = 1; i <= hum; i++)
        E.push_back(make_pair((360 - d) * m + i * 360 * m, 1)); 
}

void solve(int cs)
{
    hum = 0;
    int n;
    scanf("%d", &n);    
    vector<tuple<int, int, int> > input;
    for (int i = 0; i < n; i++)
    {
        int d, h, m;
        scanf("%d %d %d", &d, &h, &m);
        input.push_back(make_tuple(d, h, m));
        hum += h;
    }
    E.clear();
    E.push_back(make_pair(0, hum));
    multiset<human> pool; 
    for (int i = 0; i < n; i++)
    {
        int d = get<0>(input[i]), h = get<1>(input[i]);
        llong m = get<2>(input[i]);
        for (int j = 0; j < h; j++)
            pool.insert(human(d, m + j));
    }
    int bal = hum;
    int ans = hum;
    while (bal < 2 * hum)
    {
        vector<human> toadd;
        llong t = pool.begin()->nextTime();
        while (!pool.empty() && pool.begin()->nextTime() == t)
            toadd.push_back(*pool.begin()), pool.erase(pool.begin());
        for (int i = 0; i < toadd.size(); i++)
        {
            bal += toadd[i].nextDelta();
            toadd[i].inc();
        }
        pool.insert(toadd.begin(), toadd.end());
        ans = min(ans, bal);
        eprintf("at %lld -> %d\n", t, bal);
    }
    printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
        fprintf(stderr, "%d\n", i);
    }
}

