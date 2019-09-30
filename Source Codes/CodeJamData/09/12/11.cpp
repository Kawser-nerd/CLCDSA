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

int s[20][20], w[20][20], t[20][20];
bool done[40][40];
unsigned d[40][40];

void check(int i, int j, int dis) {
  if (d[i][j] > dis) d[i][j] = dis;
}

int getTimeSN(int i, int j, int st) {
  int r = (st-t[i][j])%(s[i][j]+w[i][j]);
  if (r < s[i][j]) return st+1;
  return st+(s[i][j]+w[i][j]-r)+1;
}

int getTimeWE(int i, int j, int st) {
  int r = (st-t[i][j])%(s[i][j]+w[i][j]);
  if (r < s[i][j]) return st+(s[i][j]-r)+1;
  return st+1;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
          int n,m;
          fin >> n >> m;
          FI(i, 0, n) FI(j, 0, m) {
            fin >> s[i][j] >> w[i][j] >> t[i][j];
            t[i][j] %= (s[i][j]+w[i][j]);
            t[i][j] -= s[i][j]+w[i][j];
          }

          mset(done, 0);
          mset(d, 255);
          d[0][0] = 0;

          while (1) {
            int si = -1, sj;
            FI(i,0,n*2) FI(j,0,m*2)
              if (!done[i][j] && (si < 0 || d[si][sj] > d[i][j])) {
                si = i; sj = j;
              }

            if (si == n*2-1 && sj == m*2-1) break;
            done[si][sj] = true;
            int t = d[si][sj];
            if (si % 2 == 0) {
              if (si+1 < n*2) check(si+1, sj, getTimeSN(si/2, sj/2, t));
              if (si-1 >= 0) check(si-1, sj, t+2);
            } else {
              if (si+1 < n*2) check(si+1, sj, t+2);
              if (si-1 >= 0) check(si-1, sj, getTimeSN(si/2, sj/2, t));
            }
            if (sj % 2 == 0) {
              if (sj+1 < m*2) check(si, sj+1, getTimeWE(si/2, sj/2, t));
              if (sj-1 >= 0) check(si, sj-1, t+2);
            } else {
              if (sj+1 < m*2) check(si, sj+1, t+2);
              if (sj-1 >= 0) check(si, sj-1, getTimeWE(si/2, sj/2, t));
            }
          }

		fout << "Case #" << tind << ": " << d[n*2-1][m*2-1] << endl;
	}
	return 0;
}
