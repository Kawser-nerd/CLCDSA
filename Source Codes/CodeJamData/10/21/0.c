#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
using namespace std;

typedef long long int64;
#define pb push_back
int cal(string a, string b)
{
    vector<string> t1, t2;
    char buff[256];

    strcpy(buff, a.c_str());
    char * ptr = strtok(buff, "/");
    while (ptr)
    {
        t1.pb(ptr);
        ptr = strtok(NULL, "/");
    }

    strcpy(buff, b.c_str());
    ptr = strtok(buff, "/");
    while (ptr)
    {
        t2.pb(ptr);
        ptr = strtok(NULL, "/");
    }
    int i = 0, j = 0;
    int n1 = t1.size(), n2 = t2.size();
    while (i < n1 && j < n2)
    {
        if (t1[i] != t2[j])
        {
            return n2 - j;
        }
        else
        {
            ++i, ++j;
        }
    }
    if (j == n2) return 0;
    else return n2 - j;
}
int main()
{
    int id = 1;
    int cas;scanf("%d", &cas);
    while (cas--)
    {
        int n, m;scanf("%d%d", &n, &m);
        vector<string> have(n+1);
        ++n;
        have[0] = "/";
        for (int i = 1; i < n; ++i) cin>>have[i];
        vector<string> need(m);
        for (int i = 0; i < m; ++i) cin>>need[i];
        int ans = 0;
        while (need.size())
        {
            int best = -1, x = 2000000000;
            for (int i = 0; i < need.size(); ++i)
            {
                int bn = 2000000000;
                for (int j = 0; j < have.size(); ++j)
                {
                    int t = cal(have[j], need[i]);
                    if (t < bn) bn = t;
                }
                if (bn < x) best = i, x = bn;
            }
            have.pb(need[best]);
            need.erase(need.begin() + best);
            ans += x;
        }
        printf("Case #%d: %d\n", id++, ans);
    }
	return 0;
}
