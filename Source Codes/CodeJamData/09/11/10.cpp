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

int base;
bool s[2000];
bool b[9][2000];
int ans[512];

int calc(int k, int b) {
  int sum = 0;
  while (k > 0) {
    int i = k % b;
    sum += i * i;
    k /= b;
  }
  return sum;
}

void work(int k) {
  if (s[k]) return;
  int k2 = calc(k, base);
  s[k] = true;
  work(k2);
  b[base-2][k] = b[base-2][k2];
}

int main()
{
  mset(b, 0);
  for (int bb = 2; bb <= 10; ++bb) {
    mset(s, 0);
    base = bb;
    s[1] = true;
    b[bb-2][1] = true;
    for (int j = 2; j < 2000; ++j) work(j);
  }

  mset(ans, 0);
  int v = 2;
  while (1) {
    int bits = 0;
    for (int bb = 2; bb <= 10; ++bb) {
      int k2 = calc(v, bb);
      if (b[bb-2][k2]) bits += 1<<(bb-2);
    }
    if (ans[bits] == 0) ans[bits] = v;
    if (bits == 511) break;
    v++;
  }
  for (int i = 511; i >= 1; --i) {
    if (ans[i] == 0) return 1;
    for (int j = 0; j <= 8; ++j) if (i & (1<<j)) {
        int k = i - (1<<j);
        if (ans[k] == 0 || ans[k] > ans[i]) ans[k] = ans[i];
    }
  }

	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase >> ws;
	for (int tind = 1; tind <= tcase; tind++)
	{
          string line;
          getline(fin, line);
          istringstream strin(line);
          vector<int> bb;
          int i;
          int bits = 0;
          while (strin >> i) {
            bits |= 1<<(i-2);
          }

          fout << "Case #" << tind << ": " << ans[bits] << endl;
	}
	return 0;
}
