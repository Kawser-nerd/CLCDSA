// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define REP(n) for(int _n=(n);_n--;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

class BipartiteGraph1
{
private:
	int U, V, N, M;
	int en, rit;
	vector<VI> E;
	VI eu, dep, Q, S;
	VI ea, eb, vst;

	int dfs(int x)
	{
		if(eu[x] == -1 && x < U) return 1;
		vst[x] = rit;
		static int y;

		if(x >= U) { // x in V
			for(int e: E[x]) if(e != eu[x]) {
				y = ea[e];
				if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) {
					eu[x] = eu[ea[e]] = e; return 1;
				}
			}
		} else { // x in U and eu[x] != -1
			y = eb[eu[x]];
			if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) return 1;
		}
		return 0;
	}

#define FG3_C1(e) {int y = adj((e), x); if(vst[y] != rit) {vst[y] = rit; dep[y] = dep[x] + 1; Q[tail++] = y;}}

	int bfs()
	{
		++rit;
		int sn = 0;
		int head = 0, tail = 0;
		FOR(i,0,U) if(eu[i] == -1)
		{
			dep[i] = 0;
			vst[i] = rit;
			Q[tail++] = i;
		}
		while(head < tail)
		{
			int x = Q[head];
			if(eu[x] == -1 && x >= U)
			{
				FOR(i,head,tail) if(eu[Q[i]] == -1) S[sn++] = Q[i];
				break;
			}
			++head;
			if(x < U)
			{
				for(int e: E[x]) if(e != eu[x]) FG3_C1(e)
			}
			else FG3_C1(eu[x]) // x in V and eu[x] != -1
		}
		return sn;
	}

public:
	BipartiteGraph1(int u, int v, int m)
	{
		U = u; V = v; N = u+v; M = m; en = 0, rit = 0;
		E.resize(N); eu.resize(N, -1); ea.resize(m); eb.resize(m);
		vst.resize(N, 0); dep.resize(N); Q.resize(N); S.resize(v);
	}
	int adj(int e, int a) const {return a ^ ea[e] ^ eb[e];}
	void addEdge(int a, int b)
	{
		E[a].PB(en);
		E[b+U].PB(en);
		ea[en] = a;
		eb[en] = b+U;
		++en;
	}
	int matching()
	{
		int res = 0, sn;
		while((sn = bfs()) > 0)
		{
			++rit;
			FOR(i,0,sn) res += dfs(S[i]);
		}
		return res;
	}
	VP getPairs()
	{
		int n = 0;
		FOR(i,0,U) n += eu[i] != -1;
		VP P(n);
		n = 0;
		FOR(i,0,U) if(eu[i] != -1) P[n++] = PII(i, adj(eu[i], i)-U);
		return P;
	}
};

#define MAXN (104)
#define MAX2N (204)

int S[MAX2N];
int D[MAX2N];
int R[MAXN];
int C[MAXN];

int B0[MAXN][MAXN];
int B[MAXN][MAXN];

int main()
{
	IO();
	cint1(TT);
	FOR(T,1,TT+1)
	{
		MSET(S,0);
		MSET(D,0);
		MSET(R,0);
		MSET(C,0);
		MSET(B0,0);

		cint2(N,M);
		REP(M)
		{
			char a;
			cin >> a;
			cint2(r,c);
			--r; --c;
			if(a == '+' || a == 'o')
			{
				int s = r + c;
				int d = r - c + N - 1;
				S[s] = 1;
				D[d] = 1;
				B0[r][c] |= 1;
			}
			if(a == 'x' || a == 'o')
			{
				R[r] = 1;
				C[c] = 1;
				B0[r][c] |= 2;
			}
		}
		memcpy(B, B0, sizeof(B0));

		// adding 'x'
		{
			int r = 0;
			int c = 0;
			while(1)
			{
				while(r < N && R[r]) ++r;
				if(r == N) break;
				while(c < N && C[c]) ++c;

				B[r++][c++] |= 2;
			}
		}

		// adding '+'
		{
			int N2 = 2*N - 1;
			VP E;
			FOR(r,0,N) FOR(c,0,N)
			{
				int s = r + c;
				int d = r - c + N - 1;
				if(!S[s] && !D[d]) E.PB(PII(s,d));
			}
			BipartiteGraph1 G(N2, N2, SZ(E));
			for(PII e: E) G.addEdge(e._1, e._2);

			G.matching();
			VP P = G.getPairs();
			for(PII e: P)
			{
				int s, d;
				tie(s, d) = e;
				d -= N - 1;
				int r = (s + d) / 2;
				int c = (s - d) / 2;
				B[r][c] |= 1;
			}
		}

		int solx = 0;
		int soly = 0;
		FOR(r,0,N) FOR(c,0,N)
		{
			solx += (B[r][c] & 1) + (B[r][c] >> 1);
			soly += B[r][c] != B0[r][c];
		}

		printf("Case #%d: %d %d\n", T, solx, soly);
		FOR(r,0,N) FOR(c,0,N) if(B[r][c] != B0[r][c])
		{
			const char ANS[5] = " +xo";
			printf("%c %d %d\n", ANS[B[r][c]], r+1, c+1);
		}
	}

	return 0;
}