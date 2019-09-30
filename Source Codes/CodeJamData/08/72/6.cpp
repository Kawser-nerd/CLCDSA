#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
#include <set>
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

const int mm = 10007;
bool bun = false;
set<int> ans;
int n;
int a[110];

bool report(int q)
{
	//cout << "test " << q << endl;
	ans.insert(q);
	if (ans.size() > 2) bun = true;
	return bun;
}

void work(int m, int b[], int r)
{
	if (m <= 1)
	{
		//cout << "here" << endl;
		bun = true;
		return;
	}

	int i, r1;
	int c[100];
	i = 2;
	while (i < m && b[i] == b[0]) i+=2;
	if (i >= m)
	{
		r1 = r;
		if (i == m)
		{
			r1 = (r1+b[i%2])%mm;
			if (report(r1)) return;
		}
		else
		{
			int k = 0;
			for (int j = i%2; j < m; j+=2)
				c[k++] = b[j];
			work(k, c, r);
			if (bun) return;
		}
	}

	i = 3;
	while (i < m && b[i] == b[1]) i+=2;
	if (i >= m)
	{
		r1 = r;
		if (i == m)
		{
			r1 = (r1+b[i%2])%mm;
			if (report(r1)) return;
		}
		else
		{
			int k = 0;
			for (int j = i%2; j < m; j+=2)
				c[k++] = b[j];
			work(k, c, r);
			if (bun) return;
		}
	}
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		bun = false;
		ans.clear();

		//cout << "case " << tind << endl;
		fin >> n;
		FI(i,0,n) fin >> a[i];
		int b[110];
		FI(i,0,n-1) b[i] = (a[i+1]-a[i]+mm)%mm;
		work(n-1, b, a[n-1]);
		
		if (bun || ans.size() != 1)
			fout << "Case #" << tind << ": UNKNOWN" << endl;
		else
			fout << "Case #" << tind << ": " << (*ans.begin()) << endl;
	}
	return 0;
}
