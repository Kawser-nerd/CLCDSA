#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

ifstream fin ("B.in");
ofstream fout ("B.out");

int N;
ll T;
ll m[MAXN];

bool works (ll x)
{
    ll ntime = x / N, ncnt = x % N;
    
    ll tot = 0;
    for (int i = 0; i < N; i++)
    {
        tot += (ntime / m[i]) + 1;
        if (tot >= T) return true;
        
        if (i == ncnt)
            ntime--;
    }
    return tot >= T;
}

int main()
{
    int ntest = 0;
    fin >> ntest;
    
    for (int test = 0; test < ntest; test++)
    {
        fin >> N >> T;
        for (int i = 0; i < N; i++)
            fin >> m[i];
        
        ll lo = 0, hi = 1e18;
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (works (mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        fout << "Case #" << test + 1 << ": " << lo % N + 1 << "\n";
    }
    return 0;
}