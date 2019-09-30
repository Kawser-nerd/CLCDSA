#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
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

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SEC second

int main() {
	int N; cin >> N;
	vector<int> A(N); for (auto &a : A) cin >> a;

	ull cnt = 0;
	REP(i, N-1) {
		cnt += A[i] / 2;
		if ((A[i] % 2) == 1 and A[i + 1] > 0) {
			A[i + 1]--;
			cnt++;
		}
	}
	cnt += A.back() / 2;

	cout << cnt << endl;
	return 0;
}