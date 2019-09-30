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
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)

int main()
{
	int cas = Rint();
	for (int caseID = 1; caseID <= cas; ++caseID)
	{
		int n = Rint();
		vector<string> vec(n);
		rep(i, 0, n) cin>>vec[i];
		vector<double> wp(n,0);
		vector<double> owp(n,0);
		vector<double> oowp(n,0);
		rep(i, 0, n)
		{
			int cpt = 0, win = 0;
			foreach(it, vec[i])
			{
				if (*it == '0' || *it == '1')
				{
					++cpt;
					if (*it == '1') ++win;
				}
			}
			wp[i] = 1. * win / cpt;
			
		}
		rep(i, 0, n)
		{
			vector<double> wp(n, 0);
			rep(j, 0, n)
			{
				int cnt = 0, win = 0;
				rep(k, 0, n) if (k != i)
				{
					if (vec[j][k] != '.')
					{
						++cnt;
						if (vec[j][k] == '1') ++win;
					}
				}
				wp[j] = 1. * win / cnt;
			}
			int cnt = 0;
			double s = 0;
			rep(j, 0, n)
			{
				if (vec[i][j] != '.')
				{
					++cnt, s += wp[j];
				}
			}
			owp[i] = s / cnt;
		}
		rep(i, 0, n)
		{
			int cpt = 0;
			double s = 0;
			for (int j = 0; j < n; ++j)
			{
				int it = vec[i][j];
				if (it == '0' || it == '1')
				{
					++cpt;
					s += owp[j];
				}
			}
			oowp[i] = s / cpt;
		}
		printf("Case #%d:\n", caseID);
		//cerr << wp[0] << " " << owp[0] << " " << oowp[0] << endl;
		rep(i, 0, n) printf("%.10f\n", wp[i]*0.25+owp[i]*0.5+oowp[i]*0.25);
	}
	return 0;
}
