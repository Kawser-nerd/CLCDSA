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

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int i,j;
		//istringstream strin();
		int x[1000], y[1000];
		int n;
		fin >> n;
		FI(i,0,n) fin >> x[i];
		FI(i,0,n) fin >> y[i];
		sort(x, x+n);
		sort(y, y+n);
		ll ans = 0;
		FI(i,0,n) ans += (ll)x[i]*y[n-1-i];
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
