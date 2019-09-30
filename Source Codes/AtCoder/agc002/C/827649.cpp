#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <limits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <array>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define uinf 0x3f3f3f3f3f3f3f3f
#define CLEAR(a) a = decltype(a)()
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int ,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define VVI vector<vector<int>>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define FIN std::ifstream cin("D:\input.txt")
const int MOD = 1e9 + 7;

signed int main(void) {
	int N, L; cin >> N >> L;
	vector<int> A(N); for (auto &a : A) cin >> a;

	int pos = -1;
	REP(i, N - 1) if (A[i] + A[i + 1] >= L) {
		pos = i;
		break;
	}

	if (pos == -1) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << "Possible" << endl;
	REP(i, pos) {
		cout << i + 1 << endl;
	}
	RFOR(i, pos + 1, N - 1) {
		cout << i+1 << endl;
	}
	cout << pos+1 << endl;

	return 0;
}