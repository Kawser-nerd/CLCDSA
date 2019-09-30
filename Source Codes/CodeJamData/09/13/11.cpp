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

long long cc[41][41];
double f[50], p[50];

int main()
{
  mset(cc, 0);
  cc[0][0] = 1;
  FI(i, 1, 41) {
    cc[i][0] = 1;
    for (int j = 1; j <= i; ++j) cc[i][j] = cc[i-1][j-1]+cc[i-1][j];
    //cout << cc[i][i/2] << endl;
  }

	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
          int n,c;
          fin >> c >> n;
          mset(f, 0);
          f[0] = 0;
          for (int i = 1; i <= c; ++i) {
            mset(p, 0);
            double sum = 0;
            for (int j = 0; j <= i; ++j) {
              if (j > n) continue;
              double prob = (double)cc[i][j] * (double)cc[c-i][n-j] / cc[c][n];
              p[j] = prob;
              if (j > 0) sum += prob * f[i-j];
            }
            f[i] = (sum + 1) / (1-p[0]);
          }

          //for (int i = 0; i <= c; ++i) fout << f[i] << '\t';
          //fout << endl;
          fout << "Case #" << tind << ": " << f[c] << endl;
	}
	return 0;
}
