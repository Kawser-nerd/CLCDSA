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


//????????????
class BipartiteMatching2 {
public:
	//??????
	BipartiteMatching2() :V(0) {}
	BipartiteMatching2(int size) :V(size) {
		G.resize(size);
		match.resize(size);
		used.resize(size);
	}
	
	//u,v?????????????
	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	//?????????????????
	int max_matching() {
		int res = 0;
		fill(match.begin(), match.end(), -1);
		REP(v, V)if (match[v] < 0) {
			fill(used.begin(), used.end(), false);
			if (dfs(v))res++;
		}
		return res;
	}


private:
	const int V;          //???
	vector<vector<int>> G;//???????????
	vector<int> match;    //????????
	vector<bool> used;    //dfs???????????

						  //?????DFS???
	bool dfs(int v) {
		used[v] = true;
		REP(i, (int)G[v].size()) {
			int u = G[v][i], w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
};
using BM2 = BipartiteMatching2;




//??
int N;
vector<pair<int, int>> reds, blues;
//????
//??
void input()
{
	int a, b;
	cin >> N;
	REP(i, N) {
		cin >> a >> b;
		reds.push_back({ a,b });
	}
	REP(i, N) {
		cin >> a >> b;
		blues.push_back({ a,b });
	}
}


//??
void calc()
{
	BM2 bm2 = BM2(2 * N);
	REP(i, N)REP(j, N) {
		auto red = reds[i];
		auto blue = blues[j];
		if (red.first < blue.first && red.second < blue.second)
			bm2.add_edge(i, N + j);
	}
	cout << bm2.max_matching() << endl;
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
} ./Main.cpp:67:26: warning: '&&' within '||' [-Wlogical-op-parentheses]
                        if (w < 0 || !used[w] && dfs(w)) {
                                  ~~ ~~~~~~~~~^~~~~~~~~
./Main.cpp:67:26: note: place parentheses around the '&&' expression to silence this warning
                        if (w < 0 || !used[w] && dfs(w)) {
                                              ^
                                     (                 )
1 warning generated.