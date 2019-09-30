#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);


//??
int N;
vector<LL> a, b;






//????
//??
void input()
{
	cin >> N;
	a.resize(N); REP(i, N)cin >> a[i];
	b.resize(N); REP(i, N)cin >> b[i];
}

bool bit(vector<LL> a, vector<LL> b, int level)
{
	LL res = 0;
	level++;
	for (auto& num : a)num %= (1ll << (level));
	for (auto& num : b)num %= (1ll << (level));
	sort(b.begin(), b.end());
	level--;


	for (auto num : a) {
		//[T,2T)
		LL l = (1ll << level) - num;
		LL r = 2 * (1ll << level) - num;
		res += distance(lower_bound(b.begin(), b.end(), l), lower_bound(b.begin(), b.end(), r));
		//cerr << res << "  ";
		l = 3 * (1ll << level) - num;
	    r = 4 * (1ll << level) - num;
		res += distance(lower_bound(b.begin(), b.end(), l), lower_bound(b.begin(), b.end(), r));
		//cerr << res << endl;
	}
	//cerr << endl;
	return res % 2;
}

//??
void calc()
{
	const int siz = 30;
	vector<bool> res;
	REP(i, siz) {
		res.push_back(bit(a, b, i));
	}

	LL ans = 0;
	while (!res.empty()) {
		ans <<= 1;
		ans += res.back();
		res.pop_back();
	}
	cout << ans << endl;
}


//??
void output()
{

}


//????
void debug()
{
	int N;
	cin>>N;
}


//?????
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}