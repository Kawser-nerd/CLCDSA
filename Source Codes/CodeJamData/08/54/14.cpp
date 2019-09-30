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

int m[110][110];
int mm = 10007;

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		mset(m, 0);
		int w,h,r;
		int i,j;
		//istringstream strin();
		fin >> w >> h >> r;
		int x,y;
		FI(i,0,r)
		{
			fin >> x >> y;
			m[x-1][y-1] = -1;
		}
		m[0][0] = 1;
		FI(i,0,w) FI(j,0,h) if (m[i][j] > 0)
		{
			x = i+1; y = j+2;
			if (m[x][y] >= 0) m[x][y] = (m[x][y]+m[i][j])%mm;
			x = i+2; y = j+1;
			if (m[x][y] >= 0) m[x][y] = (m[x][y]+m[i][j])%mm;
		}

		int ans = m[w-1][h-1];
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
