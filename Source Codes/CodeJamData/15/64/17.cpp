// @betaveros v1.1 :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#ifdef CDEBUG
#define debugf(...) fputs("\033[35m", stderr);fprintf(stderr, __VA_ARGS__);fputs("\033[0m", stderr)
#else
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

const int FM = 20008, FN = 208;
vector<int> graph[FN];
int n, m, k;
bool shortlink;
void readInput() {
	scan_ddd(n, m, k);
	shortlink = false;
	fori (i, 0, n) graph[i].clear();
	repeat(m) {
		int a, b;
		scan_dd(a, b);
		if (a == 0 && b == n - 1) shortlink = true;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
int fdist[FN], rdist[FN];
bool vis[FN];

// from IOICamp 2014!!!
struct E {
	int k,c;
	E(){}
	E( int _k, int _c ):k(_k),c(_c){}
} es[FM*2];

struct Flow {
	// n 為點數，m 為弧數
	// dis 為從源點藉由剩餘流量非零的弧到某點的最短距
	// e 記錄每個點連出去的弧的編號
	// 此程式碼限定源點為 0,匯點為 n-1

	int n,m,dis[FN],ptr[FN];
	int qq[FN],qr,ql;
	vector<int> e[FN];
	// init 為初始化函數
	void init( int _n ) {
		n=_n; m=0;
		for ( int i=0; i<n; i++ ) e[i]=vector<int>();
	}
	// 在網路流模型添加一條由 a 到 b 且流量限制為 c 的弧
	void add( int a, int b, int c ) {
		e[a].push_back(m); es[m]=E(b,c); m++;
		e[b].push_back(m); es[m]=E(a,0); m++;
	}
	// 使用 bfs 得到 dis 陣列的值
	bool BFS() {
		memset(dis,-1,n*sizeof(int));
		ql=qr=0;
		qq[qr++]=0;
		dis[0]=0;
		while ( ql!=qr && dis[n-1]==-1 ) {
			int p=qq[ql++];
			for(int i=0;i < (int)e[p].size(); i++) {
				E ee=es[ e[p][i] ];
				if ( ee.c==0 || dis[ee.k]!=-1 ) continue;
				dis[ee.k]=dis[p]+1;
				qq[qr++]=ee.k;
			}
		}
		return dis[n-1]!=-1;
	}
	// 回傳在分層圖中，找出一條從 p 出發流量不超過 c 的增廣路並回傳值
	int go( int p, int c ) {
		if ( p==n-1 ) return c;
		int tmp;
		// 若從 i=0 開始，也就是每次呼叫函式是都檢查該點所有連出的弧
		// 此演算法的時間複雜度仍會和 Edmonds-Karps Algorithm 一樣

		for(int i=ptr[p]; i<(int)e[p].size(); i++) {
			E &ee=es[e[p][i]];
			// 若剩餘流量為零或該弧不為分層圖上的弧就跳過
			if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
			tmp=go(ee.k,min(c,ee.c));
			// 若能藉由該弧流到匯點，就回傳結果
			// 並設 ptr[p]=i 代表下次使用此函式直接從第 ptr[p] 個弧檢查就行了
			// 於是每條弧至多都只會出現一次檢查時沿該弧找不到增廣路的情形
			// 失誤的次數為 O(m), 而每次找到增廣路的弧數為 O(n)
			// 於是能確保每次在分層圖上找到所有最短增廣路的時間複雜度為 O(nm)

			if(tmp != 0){
				ee.c-=tmp; es[e[p][i]^1].c+=tmp;
				ptr[p]=i;
				return tmp;
			}
		}
		ptr[p] = (int)e[p].size();
		return 0;
	}
	// 此為求最大流的主函式
	int maxflow() {
		long long ret=0; // 儲存答案的變數

		// 每次要找所有最短增廣路之前
		// 先使用 bfs 以便知道哪些弧是分層圖上的弧
		// 並當已經無法從源點到匯點時結束 while 迴圈
		while ( BFS() ){
			for(int i=0;i<n;i++)ptr[i]=0;

			// 以 bfs 得到分層圖後一直找弧全在分層圖上的增廣路直到找不到為止
			// 由於每次找到增廣路後分層圖上至少會有一條弧剩餘流量減至 0
			// 故至多找到 O(m) 條增廣路
			while(true){
				int tmp=go(0,OO);
				if(tmp)ret+=tmp;
				else break;
			}
		}
		return ret;
	}
} flow;

void seek(int start, int dist[]) {
	fori (i, 0, n) {
		vis[i] = false;
		dist[i] = OO;
	}
	dist[start] = 0;
	int cur = start;
	while (cur != -1) {
		vis[cur] = true;
		for (int to : graph[cur]) {
			minify(dist[to], dist[cur] + 1);
		}
		cur = -1;
		int cdist = OO;
		fori (i, 0, n) {
			if (!vis[i] && dist[i] < cdist) {
				cur = i;
				cdist = dist[i];
			}
		}
	}
}

bool tight(int v) {
	return fdist[v] + rdist[v] == fdist[n-1];
}
int solve() {
	seek(0, fdist);
	seek(n-1, rdist);
	assert(fdist[n-1] == rdist[0]);
	if (shortlink) return fdist[n-1] + 1;
	flow.init(2*n);
	fori (i, 0, n) {
		flow.add(2*i + 1, 2*i, 1);
		if (tight(i)) {
			for (int to : graph[i]) {
				if (tight(to)) flow.add(2*i, 2*to + 1, 1);
			}
		}
	}
	int f = flow.maxflow();
	debugf("flow = %d\n", f);
	return fdist[n-1] + ((k - 1) >= f ? 2 : 1);
}

void tc(int tci) {
	readInput();

	printf("Case #%d: %d", tci, solve());
	printf("\n");
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
