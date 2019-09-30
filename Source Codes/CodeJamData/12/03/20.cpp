#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>
#include <numeric>
#include <fstream>

using namespace std;

#define		ALL(c)	(c).begin(),(c).end()
#define		SZ(c)	int((c).size())
#define		LEN(s)	int((s).length())
#define		FOR(i,n)	for(int i=0;i<(n);++i)
#define		FORD(i,a,b)	for(int i=(a);i<=(b);++i)
#define		FORR(i,a,b)	for(int i=(b);i>=(a);--i)

typedef istringstream iss;
typedef ostringstream oss;
typedef long double ld;
typedef long long i64;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef vector<ld> vd;
typedef vector<vd> vvd;

typedef vector<string> vs;

const i64 d18 = 1000000000000000000LL;
const ld eps = 1e-9;
const ld pi = atan2(0.0, -1.0);
template<class T> T sqr(T a) { return a * a; }
i64 abs(i64 a) { return (a >= 0) ? a : -a; }

ofstream LOG("log.txt");

ifstream fin;
ofstream fout;

int arr2n(const vi& r)
{
	int n = 0;
	FORR(i, 0, SZ(r)-1) n = 10 * n + r[i];
	return n;
}

void n2arr(int n, vi& a)
{
	a.clear();
	if (n == 0) a.push_back(0);
	while (n > 0)
	{
		a.push_back(n%10);
		n /= 10;
	}
}

void solve_case(int TN)
{
	int A, B;
	fin >> A >> B;
	map<int,int> Cnt;
	FORD(x, A, B)
	{
		vi a;
		n2arr(x, a);
		int y = arr2n(a);
		FOR(i, SZ(a))
		{
			rotate(a.begin(), a.begin()+1, a.end());
			if (a.back() != 0)
				y = min(y, arr2n(a));
		}
		++Cnt[y];
	}
	i64 ans = 0;
	for (map<int,int>::iterator it = Cnt.begin(); it != Cnt.end(); ++it)
		ans += it->second * (i64)(it->second - 1) / 2;
	fout << "Case #" << TN << ": " << ans << endl;
	cout << "Case #" << TN << ": " << ans << endl;
}

int main()
{
	fin.open("C.in"); 
	fout.open("C.out");

	int T; 
	fin >> T;
	FOR(tt, T)
	{
		solve_case(tt+1);
	}

	return 0;	
}
