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
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int main()
{
	int tcase = 0;
	ifstream fin("a.in");
	ofstream fout("a.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int s, q;
		string line;
		fin >> s;
		getline(fin, line);
		map<string, int> ser;
		int i,j;
		for (i = 0; i < s; i++)
		{
			getline(fin, line);
			ser[line] = i;
		}
		int a[1100];
		fin >> q;
		getline(fin, line);
		for (i = 0; i < q; i++)
		{
			getline(fin, line);
			if (ser.count(line) > 0)
				a[i] = ser[line];
			else
				a[i] = -1;
		}
		
		int ans = 0;
		bool b[110];
		int t = s;
		mset(b, 0);
		i = 0;
		while (i < q)
		{
			j = a[i];
			if (j < 0)
			{
				i++;
				continue;
			}
			if (!b[j] && t == 1)
			{
				ans++;
				mset(b, 0);
				t = s;
				continue;
			}
			if (!b[j])
			{
				b[j] = true;
				t--;
			}
			i++;
		}
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
