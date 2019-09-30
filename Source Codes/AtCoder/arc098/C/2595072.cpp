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

void append(vector<int>& mini, vector<int>& tmp)
{
	sort(tmp.begin(), tmp.end());
	if(tmp.size()>K-1)
		copy(tmp.begin(), tmp.end() - K + 1, back_inserter(mini));
	tmp.clear();
}

int X_Y(int base) {
	vector<int> mini, tmp;
	REP(i, N) {
		if (A[i] >= base) {
			tmp.push_back(A[i]);
		}
		else {
			append(mini, tmp);
		}
	}
	append(mini, tmp);

	if (mini.size() < Q)return INF;
	sort(mini.begin(), mini.end());
	return mini[Q - 1] - mini[0];
}

//??
void calc()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	set<int> si;
	for (auto num : A)si.insert(num);
	for (auto num : si)pq.push(num);

	int ans = INF;
	REP(i,N){
		int base = pq.top(); pq.pop();
		int tmp = X_Y(base);
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