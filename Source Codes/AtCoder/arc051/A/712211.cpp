// ConsoleApplication1.cpp : ????? ????????????? ???????????
//


#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <sstream>

#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for (long long i=(b)-1;i>=(a);i--)
#define REP(i,n) for (unsigned long long i=0;i<(n);i++)
#define RREP(i,n) for (long long i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define llinf LLONG_MAX/3
#define LLINF LLONG_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SCD second

using namespace std;

signed main()
{
	double x1, y1, r;
	double x2, y2, x3, y3;

	cin >> x1;
	cin >> y1;
	cin >> r;
	cin >> x2;
	cin >> y2;
	cin >> x3;
	cin >> y3;

	if (x2 <= x1 - r &&
		x1 + r <= x3 &&
		y2 <= y1 - r &&
		y1 + r <= y3) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}

	if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= r * r &&
		(x3 - x1) * (x3 - x1) + (y2 - y1) * (y2 - y1) <= r * r &&
		(x2 - x1) * (x2 - x1) + (y3 - y1) * (y3 - y1) <= r * r &&
		(x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) <= r * r) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}

	return 0;
}