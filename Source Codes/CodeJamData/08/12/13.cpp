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
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int malt[2100];
int tu[2100];
bool sol[2100];
bool b[2100][2100];
bool ret[2100];
int q[2100];
int n,m;

bool work()
{
	int r = 0, w = 0;
	FI(i,0,m) if (!sol[i] && tu[i] == 0)
	{
		if (malt[i] < 0) return false;
		q[w++] = i;
		sol[i] = true;
	}
	while (r < w)
	{
		int id = q[r++];
		int k = malt[id];
		if (!ret[k])
		{
			ret[k] = true;
			FI(i,0,m) if (!sol[i] && b[i][k])
			{
				tu[i]--;
				if (tu[i] == 0)
				{
					if (malt[i] < 0) return false;
					q[w++] = i;
					sol[i] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		mset(b, 0);
		mset(tu, 0);
		mset(sol, 0);
		mset(malt, 255);
		mset(ret, 0);
		//istringstream strin();
		fin >> n >> m;
		FI(i,0,m)
		{
			int t;
			fin >> t;
			int p,q;
			int k = 0;
			FI(j,0,t)
			{
				fin >> p >> q;
				p--;
				if (q == 1) malt[i] = p;
				else
				{
					if (!b[i][p])
					{
						b[i][p] = true;
						tu[i]++;
					}
				}
			}
			if (malt[i] >= 0 && b[i][malt[i]]) sol[i] = true;
		}
		fout << "Case #" << tind << ":";
		if (!work())
			fout << " IMPOSSIBLE" << endl;
		else
		{
			FI(j,0,n) if (ret[j]) fout << " 1"; else fout << " 0";
			fout << endl;
		}
	}
	return 0;
}
