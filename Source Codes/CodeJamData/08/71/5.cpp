#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
#include <map>
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

int n, m;
vint e[1100];
map<string, int> z;

int getid(string str)
{
	if (z.count(str) == 0)
	{
		int p = z.size();
		z[str] = p;
		//cout << str << ' ' << p << endl;
		return p;
	}
	return z[str];
}

int work(int v)
{
	vint a;
	FI(i,0,e[v].size())
	{
		a.push_back(work(e[v][i]));
	}
	sort(a.begin(), a.end());
	if (a.size() == 0)
	{
		return 1;
	}
	int ret = e[v].size()+1;
	for (int i = 0; i < e[v].size(); i++)
	{
		int q = a[e[v].size()-1-i]+i;
		ret = max(ret, q);
	}
	return ret;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		z.clear();
		fin >> n;
		string str;
		FI(i,0,n)
		{
			fin >> str;
			int k = getid(str);
			fin >> m;
			FI(j,0,m)
			{
				fin >> str;
				if (str[0] >= 'a' && str[0] <= 'z')
				{
				}
				else
				{
					int k1 = getid(str);
					e[k].push_back(k1);
				}
			}
		}
		
		int ans = work(0);
		fout << "Case #" << tind << ": " << ans << endl;
		FI(i,0,n) e[i].clear();
	}
	return 0;
}
