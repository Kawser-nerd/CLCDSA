#define _CRT_SECURE_NO_DEPRECATE
#include<ctime>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<numeric>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(I,S,N) for(int I=(S);I<(N);++I)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";int __prv;REP(__prv,sz(X)-1) cout<<(X)[__prv]<<",";cout<<(X).back()<<"}"<<endl;}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define SS stringstream
template<typename T> string tos(T q,int w=0){SS A;A.flags(ios::fixed);A.precision(w);A<<q;string s;A>>s;return s;}
template<typename T> T sto(string s){SS A(s);T t;A>>t;return t;}
template<typename T> vector<T > s2v(string s){SS A(s);vector<T > ans;while(A&&!A.eof()){T t;A>>t;ans.pb(t);}return ans;}
	
template<typename T> class Rybak {
public:
	Rybak(int size = 0) : _a(size) {}
	int size() {return sz(_a);}
	void clear() {_a.clear();}
	void resize(int size) {clear();_a.resize(size);}
	void add(int pos,T count) {
		int l = 0, r = sz(_a), m;
		while(l < r) {
			m = (l+r)/2;
			if(pos <= m) r = m, _a[m] += count;
			else l = m+1;
		}
	}
	T query(int a, int b) {
		return _q(b) - _q(a);
	}
private:
	vector<T> _a;
	T _q(int pos) {
		int l = 0, r = sz(_a), m;
		T sum = T();
		while(l < r) {
			m = (l+r)/2;
			if(pos <= m) r = m;
			else l = m+1, sum += _a[m];
		}
		return sum;
	}
};

// end of pre-inserted code

#define DIM 1100000
int ans[DIM];

int main() {
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d ",&tc);
	FOR(tn,1,tc+1) {
		cerr << tn << endl;
		lint timer = clock();
		int n;
		scanf("%d",&n);
		Rybak<lint> a(n);
		REP(i,n) a.add(i,1);
		int p = 0;
		FOR(i,1,n+1) {
			int q = i;
			if(q  % (n + 1 - i) != 0)
				q = q % (n + 1 - i);
			else 
				q = (n + 1 - i);
			// 0 < q <= n + 1 - i
			int fr = a.query(p,n);
			if(fr < q) {
				q -= fr;
				p = 0;				
			}
			int l = p, r = n;
			while(l+1 < r) {
				int m = (l+r)/2;
				int t = a.query(p,m);
				if(t < q) l = m;
				else r = m;
			}
			// a.query(p, l) = i-1, a.query(p, l+1) = i
			p = l;
			a.add(p,-1);
			ans[p] = i;
		}
		int m;
		scanf("%d",&m);
		printf("Case #%d:",tn);
		REP(i,m) {
			int y;
			scanf("%d",&y);
			printf(" %d",ans[y-1]);
		}
		printf("\n");
		cerr << (clock() - timer) << endl;
	}
	fclose(stdout);
	return 0;
}