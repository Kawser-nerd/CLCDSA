#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
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

int loc[1000][1000];
int a[2000000];
int s, r;

int main()
{
	mset(loc, 255);
	a[0] = 1;
	a[1] = 5;
	loc[a[0]][a[1]] = 0;
	for (int i = 2; ; i++)
	{
		a[i] = (a[i-1]*6-a[i-2]*4+1+4000) % 1000;
		if (loc[a[i-1]][a[i]] >= 0)
		{
			s = loc[a[i-1]][a[i]];
			r = i-1-s;
			break;
		}
		loc[a[i-1]][a[i]] = i-1;
		//cout << a[i] << endl;
	}
	//cout << s << ' ' << r << endl;
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int n;
		fin >> n;
		int ans;
		if (n < r+s) ans = a[n];
		else ans = a[s+(n-s)%r];
		fout << "Case #" << tind << ": " << setfill('0') << setw(3) << ans << endl;
	}
	return 0;
}
