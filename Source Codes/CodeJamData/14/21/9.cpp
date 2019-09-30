#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int INF = 1000000000;
const int MOD = 1000000007;

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int t;
    cin >> t;
    FOR(ttt,0,t)
    {
        int n;
        cin >> n;
        vector<vector<pair<char,int> > > a;
        FOR(i,0,n)
        {
            string s;
            cin >> s;
            vector<pair<char,int> > b;
            b.push_back(MP(s[0] , 1));
            FOR(j,1,s.size())
            {
                if (s[j] == s[j - 1])
                {
                    b.back().second++;
                }
                else
                {
                    b.push_back(MP(s[j] , 1));
                }
            }
            a.push_back(b);
        }
        bool ok = 1;
        FOR(i,1,n)
        {
            if (a[i].size() != a[0].size())
            {
                ok = 0;
                break;
            }
            FOR(j,0,a[0].size())
                if (a[i][j].first != a[0][j].first)
                    ok = 0;
        }
        printf("Case #%d: " , ttt + 1);
        if (!ok)
        {
            cout << "Fegla Won\n";
        }
        else
        {
            int res = 0;
            FOR(i,0,a[0].size())
            {
                vector<int> b;
                FOR(j,0,n)
                {
                    b.push_back(a[j][i].second);
                }
                sort(ALL(b));
                FOR(j,0,b.size())
                    res += abs(b[j] - b[b.size() / 2]);
            }
            cout << res << endl;
        }

    }

    return 0;
}

