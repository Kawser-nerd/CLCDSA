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
	
// end of pre-inserted code

#define DIM 1100000

//lint t[DIM];
int cc[DIM];

struct  {
	int p;
	int h;
} h[DIM];

int inline find(int u) {
	while(h[u].p != u) {
		h[u].p = h[h[u].p].p;
		u = h[u].p;
	}
	return u;
}

void inline uni(int u, int v) {
	if(h[u].h > h[v].h) {
		h[v].p = u;
	}
	else {
		h[u].p = v;
		if(h[v].h == h[u].h) {
			h[v].h += 1;
		}
	}
}

bool inline prime(lint x) {
	if(x == 2) return true;
	if(x % 2 == 0) return false;
	lint k = 3;
	while(k*k <= x) {
		if(x % k == 0) return false;
		k += 2;
	}
	return true;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d ",&tc);
	FOR(tn,1,tc+1) {
		cerr << tn << endl;
		lint timer = clock();
		lint a, b, p;
		scanf("%lld %lld %lld ",&a,&b,&p);

		for(lint k = a; k <= b; ++k) {
			h[k-a].p = k-a;
			h[k-a].h = 0;
		}

		lint x = p;
		while(x <= b-a) {
			if(prime(x)) {
				lint f = (a / x) * x;
				if(f < a) f += x;
				// f >= a
				while(f + x <= b){
					int u = find(f-a );
					int v = find(f + x - a);
					uni(u, v);
					f += x;
				}
			}
			++x;
		}
		memset(cc,0,sizeof(cc[0])*(b-a+1));
		for(lint k = a; k <= b; ++k) {
			++cc[find(k-a)];
		}
		int ans = 0;
		REP(i,b-a+1) {
			ans += (cc[i] != 0);
		}

		//sort(t,t+(b-a+1));
		//int ans = unique(t,t+(b-a+1)) - t;
		printf("Case #%d: %d\n",tn,ans);
		//cerr << ( clock() - timer) << endl;
	}
	fclose(stdout);
	return 0;
}