#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <sstream>

#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for (long long i=(b)-1;i>=(a);i--)
#define REP(i,n) for (long long i=0;i<(n);i++)
#define RREP(i,n) for (long long i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define llinf LLONG_MAX/3
#define LLINF LLONG_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PLL pair<long long,long long>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VLL vector<long long>
#define VULL vector<unsigned long long>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SCD second

using namespace std;

const LL ANS_MAX = 1000000007;

struct Greater
{
	bool operator()(const LL& a, const LL& b)
	{
		return a > b;
	}
};

static bool greaterLL(const LL& a, const LL& b)
{
	return a > b;
}


// ARC074C
int main()
{
	LL ret = - LLINF;

	LL N;
	cin >> N;

	VLL a(3 * N);
	for (size_t i = 0; i < 3 * N; i++) {
		cin >> a[i];
	}

	VLL a0(N);
	VLL sum0(N + 1, 0);
	for (size_t i = 0; i < N; i++) {
		a0[i] = a[i];
		sum0[0] += a0[i];
	}
	make_heap(a0.begin(), a0.end(), greaterLL);

	for (size_t i = 0; i < N; i++) {
		a0.push_back(a[N + i]);
		sum0[i + 1] = sum0[i] + a[N + i];
		push_heap(a0.begin(), a0.end(), greaterLL);
		sum0[i + 1] -= a0[0];
		pop_heap(a0.begin(), a0.end(), greaterLL);
		a0.pop_back();
	}

	VLL a1(N);
	VLL sum1(N + 1, 0);
	for (size_t i = 0; i < N; i++) {
		a1[i] = a[2 * N + i];
		sum1[0] += a1[i];
	}
	make_heap(a1.begin(), a1.end());

	for (size_t i = 0; i < N; i++) {
		a1.push_back(a[N + N  - i - 1]);
		sum1[i + 1] = sum1[i] + a[N + N - i - 1];
		push_heap(a1.begin(), a1.end());
		sum1[i + 1] -= a1[0];
		pop_heap(a1.begin(), a1.end());
		a1.pop_back();
	}

	for (size_t i = 0; i < N + 1; i++) {
		ret = MAX(ret, sum0[i] - sum1[N - i]);
	}

	//for (size_t i = 0; i < N; i++) {
	//	a0.push(a[i]);
	//}
	//for (size_t i = N; i < 3 * N; i++) {
	//	a1.push(a[i]);
	//}

	//LL t = a0.top();
	//LL s = a1.top();

	//make_heap(a0.begin(), a0.end(), greater);
	//pop_heap(a0.begin(), a0.end(), greater);
	//push_heap(a0.begin(), a0.end(), greater);

	//for (size_t j = 0; j < N; j++) {

	//	LL sum0 = 0;
	//	for (size_t i = 0; i < N; i++) {
	//		sum0 += a0[i];
	//	}

	//	LL sum1 = 0;
	//	for (size_t i = 0; i < N; i++) {
	//		sum1 += a1[i];
	//	}
	//	ret = MAX(ret, sum0 - sum1);
	//}

	cout << ret << endl;

#if _DEBUG
	cin >> ret;
#endif

	return 0;
}