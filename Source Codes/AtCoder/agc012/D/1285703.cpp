#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <queue>
 
#define fr first
#define sc second
#define mk make_pair
 
using namespace std;
 
struct st{
    int color, w, ind;
};
 
int n, x, y, dsu[1000001], kol[1000001];
long long f[1000001];
vector<st> vec[1000001];
vector<int>vc[1000001];
st ar[1000001];
 
bool cmp(st a, st b)
{
    return (a.w >= b.w) ? 0 : 1;
}
 
int get_dsu(int x)
{
    if(dsu[x] == x)
        return x;
    return dsu[x] = get_dsu(dsu[x]);
}
 
long long mod = 1e9 + 7;
 
long long binpow(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 1)
        return a * binpow(a, b - 1) % mod;
    else
    {
        long long h = binpow(a, b / 2);
        return h * h % mod;
    }
}
 
int main()
{
    f[0] = 1;
    for(int i = 1; i <= 1e6; i++)
    {
        dsu[i] = i;
        f[i] = f[i - 1] * i % mod;
    }
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &ar[i].color, &ar[i].w);
        ar[i].ind = i;
        vec[ar[i].color].push_back(ar[i]);
    }
 
    for(int i = 1; i <= n; i++)
        if(vec[i].size() != 0)
        {
            sort(vec[i].begin(), vec[i].end(), &cmp);
            for(int j = 0; j < vec[i].size(); j++)
                if(vec[i][j].w + vec[i][0].w <= x)
                {
                    dsu[get_dsu(vec[i][j].ind)] = get_dsu(vec[i][0].ind);
                }
        }
 
    sort(ar + 1, ar + n, &cmp);
 
    int mn = 1e9;
    for(int i = 1; i <= n; i++)
    {
        if(ar[i].color != ar[1].color && ar[1].w + ar[i].w <= y)
        {
            dsu[get_dsu(ar[i].ind)] = get_dsu(ar[1].ind);
        }
        if(ar[i].color != ar[1].color)
            mn = min(mn, i);
    }
    if(mn != 1e9)
    for(int i = 1; i <= n; i++)
        if(ar[i].color == ar[1].color && ar[mn].w + ar[i].w <= y)
            dsu[get_dsu(ar[i].ind)] = get_dsu(ar[mn].ind);
 
    for(int i = 1; i <= n; i++)
    {
        kol[get_dsu(ar[i].ind)]++;
        vc[get_dsu(ar[i].ind)].push_back(ar[i].color);
    }
 
 
    long long ans = 1;
    for(int i = 1; i <= n; i++)
    {
        if(dsu[i] == i)
        {
            long long k = 1;
            for(long long j = 0; j < kol[i]; j++)
            {
                k *= (j + 1);
                k = k % mod;
            }
            int l = 0, r = 0;
            sort(vc[i].begin(), vc[i].end());
 
            while(vc[i].size() > l)
            {
                while(vc[i][l] == vc[i][r + 1] && r < vc[i].size() - 1)
                {
                    r++;
                }
                k = k * binpow(f[r - l + 1], mod - 2) % mod;
                l = r + 1;
            }
            //cout << i << " " << k << endl;
            ans = ans * k % mod;
        }
    }
    cout << ans;
    return 0;
}