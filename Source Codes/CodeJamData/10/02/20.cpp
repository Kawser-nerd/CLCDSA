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
 
using namespace std;

#define sz(a) (LL)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair<int, int> pii;
#define LL long long
#define INF 1000000

int n, ma;
int a[1010];

int gcd(int x, int y) { return x ? gcd(y%x, x) : y; }

void makeTest()
{
    freopen("makeTest.txt", "w", stdout);
    int i, j, k;
    cout << (36870) << endl;
    for (i=1; i<=100; i++)
        for (j=1; j<=100; j++)
            if (i!=j)
                cout << 2 << " " << i << " " << j << endl;
    for (i=1; i<=30; i++) for (j=1; j<=30; j++) for (k=1; k<=30; k++)
        if (i!=j||j!=k||i!=k)
            cout << 3 << " " << i << " " << j << " " << k << endl;
}

int doubleCheck()
{
    int i;
    int y;
    int best = 0;
    int ret = 0;
    if (a[0]==2 && a[1]==4)
        a[0]=2;
    for (y=0; y<=200; y++)
    {
        int d = 0;
        for (i=0; i<n; i++) d = gcd(d, a[i]+y);
        if (d>best)
        {
            best=d;
            ret=y;
        }
    }
    return ret;
}

int main()
{
    //makeTest();

    //freopen("makeTest.txt", "r", stdin);
    //freopen("out.txt", "r", stdin);
	
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);

    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-small-attempt1b.out", "w", stdout);

    //freopen("B-small-attempt3.in", "r", stdin);
    //freopen("B-small-attempt3b.out", "w", stdout);

    //freopen("B-small-attempt4.in", "r", stdin);
    //freopen("B-small-attempt4a.out", "w", stdout);

    freopen("B-small-attempt5.in", "r", stdin);
    freopen("B-small-attempt5.out", "w", stdout);

	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);

	int numtest, test;
	cin >> numtest;

	for (test=1; test<=numtest; test++)
	{
        int ans = 0;
        int i, j;
        ma = 0;
        cin >> n;
        for (i=0; i<n; i++)
        {
            cin >> a[i];
            ma = max(a[i], ma);
        }
        int d = 0;
        for (i=0; i<n; i++) d = gcd(d, abs(ma-a[i]));
        if (d==0 || d==1 || ma%d==0) ans = 0;
        else ans = d - (ma % d);

        //if (ans != doubleCheck())
        //{
        //    cout << "WRONG" << endl;
        //    cout << test << endl;
        //}
		cout << "Case #" << (test) << ": " << ans << endl;
	}
	return 0;
}
