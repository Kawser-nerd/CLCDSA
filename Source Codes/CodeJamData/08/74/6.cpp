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

short f[4][4][1<<16];

int calc(int x, int y, int bor)
{
	if (f[x][y][bor] >= 0)
		return f[x][y][bor] == 1;
	x++; y++;
	bool a[6][6];
	mset(a, 0);
	int k = bor;
	FI(i,1,5)
		FI(j,1,5)
	{
		if (k % 2 == 1) a[i][j] = true;
		k /= 2;
	}
	int ans = 0;
	int newb = bor-(1<<((x-1)*4+y-1));
	FI(dx,-1,2)
		FI(dy,-1,2) if ((dx != 0 || dy != 0) && a[x+dx][y+dy])
	{
		if (calc(x+dx-1, y+dy-1, newb) == 0)
		{
			f[x-1][y-1][bor] = 1;
			return 1;
		}
	}
	f[x-1][y-1][bor] = 0;
	return 0;
}

int main()
{
	mset(f, 255);
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		//istringstream strin();
		int sx, sy;
		int b = 0;
		int r,c;
		fin >> r >> c;
		string str;
		FI(i,0,r)
		{
			fin >> str;
			FI(j,0,c)
			{
				char ch = str[j];
				if (ch == 'K')
				{
					sx = i; sy = j;
				}
				if (ch == 'K' || ch == '.')
					b += 1<<(i*4+j);
			}
		}

		if (calc(sx,sy,b) == 1)
			fout << "Case #" << tind << ": A" << endl;
		else
			fout << "Case #" << tind << ": B" << endl;
	}
	return 0;
}
