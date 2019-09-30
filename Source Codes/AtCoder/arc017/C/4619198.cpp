#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long N, X;
vector<long long> a, b;
map<long long, long long> ma, mb;

void rec(long long size, long long n, long long sum, vector<long long> &c, map<long long, long long> &mc)
{
    if(n >= size)
    {
        return;
    }
    if(c[n] + sum <= X)
    {
        mc[c[n] + sum]++;
        rec(size, n + 1, c[n] + sum, c, mc);
    }
    rec(size, n + 1, sum, c, mc);
}

int main()
{
    cin >> N >> X;
    for (int i = 0; i < N;i++)
    {
        long long w;
        cin >> w;
        if (i <= N / 2)
        {
            a.push_back(w);
        }
        else
        {
            b.push_back(w);
        }   
    }
    ma[0LL]++;
    mb[0LL]++;
    rec(a.size(), 0LL, 0LL, a, ma);
    rec(b.size(), 0LL, 0LL, b, mb);

    long long ans = 0LL;
    for (map<long long, long long>::iterator i = ma.begin(); i != ma.end(); i++)
    {
        long long sum = i->first;
        long long cnt = i->second;
        ans += (cnt)*mb[X - sum];
    }
    cout << ans << endl;

    return 0;
}