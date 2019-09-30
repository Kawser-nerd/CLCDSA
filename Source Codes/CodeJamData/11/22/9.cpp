#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define tr(i,x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

long long c,d;
vector<long long> h;

bool test(long long x)
{
    long long last = h[0]-x;
    for(int i=1;i<h.size();i++)
    {
        last += d;
        if(last < h[i]-x)
            last = h[i] - x;
        else if(last > h[i]+x)
            return false;
    }
    return true;
}

void tst()
{
    cin >> c >> d;
    d*=2;
    h.clear();
    for(int i=0;i<c;i++)
    {
        long long p,v;
        cin >> p >> v;
        for(int j=0;j<v;j++)
            h.pb(2*p);
    }
    sort(h.begin(),h.end());

    long long low = 0;
    long long high = 1000000000000000ll;
   
    if(test(0))
    {
        cout << 0.0 << endl;
        return;
    }

    while(high>low+1)
    {
        long long mid = low + (high-low)/2;
        if(test(mid))
            high = mid;
        else
            low = mid;

    }

    if(high%2==0)
    {
        cout << (high/2) << endl;
    }
    else
    {
        cout << (high/2) << ".5" << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        tst();
    }

}
