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
int N, K, Q;
vector<int>A;





//????
//??
void input()
{
	cin >> N >> K >> Q;
	A.resize(N);
	REP(i, N)cin >> A[i];
}

vector<vector<int>> slash(vector<int> A, int base)
{
	vector<vector<int>> res;
	vector<int> mid;
	REP(i, N) {
		if (A[i] >= base)mid.push_back(A[i]);
		else {
			res.push_back(mid);
			mid.clear();
		}
	}
	if (!mid.empty())res.push_back(mid);

	return res;
}

int X_Y(const vector<vector<int>> vv, int K,int Q) {
	vector<int> minimum;
	for (auto v : vv) {
		sort(v.begin(), v.end(),greater<int>());
		while (v.size() >= K) {
			minimum.push_back(v.back());
			v.pop_back();
		}
	}
	if (minimum.size() < Q)return INF;

	sort(minimum.begin(), minimum.end());
	return minimum[Q - 1] - minimum[0];
}

//??
void calc()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	for (auto num : A)pq.push(num);

	int ans = INF;
	while (!pq.empty()) {
		int base = pq.top(); pq.pop();
		auto vv = slash(A, base);
		int tmp = X_Y(vv, K, Q);
		if (tmp == INF)break;
		ans = min(ans,tmp);
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