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

int m[20][20];
int sh[20][20];
bool b[20][20];
int d[20][20];
int mx, my;
int stx, sty;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void upd(int x, int y, int nd)
{
	if (m[x][y] >= 0)
	{
		if (d[x][y] < 0 || nd < d[x][y])
			d[x][y] = nd;
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
		int r,c;
		fin >> r >> c;
		mset(m,255);
		int i,j;
		string str;
		FI(i,1,r+1) 
		{
			fin >> str;
			FI(j,1,c+1)
			{
				char ch = str[j-1];
				if (ch == '.')
					m[i][j] = 0;
				else if (ch == 'X')
					m[i][j] = 1;
				else if (ch == 'O')
				{
					stx = i; sty = j;
					m[i][j] = 0;
				}
			}
		}
		FI(i,1,r+1) FI(j,1,c+1) if (m[i][j] >= 0)
		{
			int dis = 10000;
			FI(x,0,r+2) FI(y,0,c+2) if (m[x][y] == -1)
			{
				int d = abs(x-i)+abs(y-j);
				if (d < dis) dis = d;
			}
			sh[i][j] = dis;
		}
		mx = r+2; my = c+2;
		mset(d, 255);
		d[stx][sty] = 0;
		mset(b, 0);
		int ans = -1;
		while (1)
		{
			int bx, by, bd = -1;
			FI(x,0,mx) FI(y,0,my)
				if (d[x][y] >= 0 && !b[x][y])
				{
					if (bd < 0 || bd > d[x][y])
					{
						bd = d[x][y];
						bx = x; by = y;
					}
				}
			if (bd < 0) break;
			if (m[bx][by] == 1)
			{
				ans = d[bx][by];
				break;
			}
			b[bx][by] = true;
			FI(z,0,4)
			{
				upd(bx+dx[z], by+dy[z], bd+1);
				int x = bx, y = by, cnt = 0;
				while (m[x+dx[z]][y+dy[z]] != -1)
				{
					x += dx[z];
					y += dy[z];
					cnt++;
				}
				if (cnt > sh[bx][by])
					upd(x, y, bd+sh[bx][by]);
			}
		}
		if (ans < 0)
			fout << "Case #" << tind << ": THE CAKE IS A LIE" << endl;
		else
			fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
