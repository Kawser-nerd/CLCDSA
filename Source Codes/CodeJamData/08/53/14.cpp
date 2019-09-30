#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

bool b[100][100];
vector<int> e[6400];
int mm,nn;

int p[6400];
bool bs[6400];

inline int conv(int x, int y)
{
	return x*nn+y;
}

inline void addp(int k1, int k2)
{
	e[k1].push_back(k2);
	e[k2].push_back(k1);
}

bool fm(int k, int inv)
{
	if (bs[k]) return false;
	bs[k] = true;
	int t = e[k].size();
	FI(i,0,t)
	{
		int k1 = e[k][i];
		if (p[k1] < 0 && k1 != inv)
		{
			p[k1] = k;
			p[k] = k1;
			return true;
		}
	}
	FI(i,0,t)
	{
		int k1 = e[k][i];
		if (p[k1] >= 0 && k1 != inv)
		{
			if (fm(p[k1], k1))
			{
				p[k] = k1;
				p[k1] = k;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int m,n;
		fin >> m >> n;
		mm = m;
		nn = n;
		if (nn % 2) nn++;
		int i,j;
		mset(b,0);
		FI(i,0,mm*nn) e[i].clear();
		string str;
		int ans = 0;
		FI(i,0,m)
		{
			fin >> str;
			FI(j,0,n) if (str[j] == '.')
			{
				ans++;
				b[i][j] = true;
			}
		}
		FI(i,0,m) FI(j,0,n) if (b[i][j])
		{
			int k = conv(i,j);
			if (b[i][j+1]) addp(k, conv(i,j+1));
			if (b[i+1][j+1]) addp(k, conv(i+1,j+1));
			if (i > 0 && b[i-1][j+1]) addp(k, conv(i-1,j+1));
		}
		mset(p,255);
		for (int i = 0; i < mm*nn; i+=2)
			if (p[i] == -1)
			{
				mset(bs, 0);
				if (fm(i, -1)) ans--;
			}

		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
