using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>

typedef long double D; typedef long long LL; typedef pair<int,int> pii;
#define ALL(v) (v).begin(),(v).end()
#define REP(i, n) for (int i (0); i < (n); i ++)
#define FORIT(a,b, it) for(__typeof(b)it(a);it!=(b);++it)
#define FOREACH(v, it) FORIT((v).begin(),(v).end(),it)
#define len(v) ((int)(v).size())
#define append push_back
#define _ make_pair
#define fi first
#define se second
#define add insert
#define remove erase
#define TWO(x) (1<<(x))
#define UNIQUE(v) (v).erase(unique(ALL(v)),(v).end())
const int infInt (1010101010);
const LL  infLL  (4 * LL (infInt) * LL (infInt));

template<class T>void pv(T a,T b){FORIT(a,b,it)cout<<*it<<" ";cout<<endl;}

inline void chmin(int&x,int y){x=min(x,y);}
inline void chmax(int&x,int y){x=max(x,y);}

int main() {
	int T;
	scanf("%d",&T);
	for (int case_nr=1; case_nr<=T; case_nr++) {
		string s;
		cin >> s;
		int n = (int) s.size();
		int the_msk = 0;
		for (int i=0; i<n; i++) if (s[i] == 'X') the_msk |= 1<<i;
		vector<long double> value (1 << n); // mask occupied
		for (int msk = (1 << n) - 2; msk >= (0); msk --) {
			value[msk] = 0;
			for (int i=0; i<n; i++) {
				int cost = n;
				int nxt = i;
				while (msk & (1<<nxt)) {
					nxt = (nxt + 1) % n;
					cost --;
				}
				value[msk] += cost + value[msk | (1<<nxt)];
			}
			value[msk] /= (long double) n;
		}
		printf("Case #%d: %.11Lf\n", case_nr, value[the_msk]);
	}
}
