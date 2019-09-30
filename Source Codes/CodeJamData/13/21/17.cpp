using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>
#include<fstream>

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
	for (int case_id=1; case_id<=T; case_id++) {
		int initial_size, n;
		cin >> initial_size >> n;
		vector<int> v (n);
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		int answer = n;
		if (initial_size > 1) {
			sort(ALL(v));
			for (int r=0; r<n; r++) { // rightmost piece to keep
				int to_remove = n - r - 1;
				int to_add = 0;
				int mx = initial_size;
				vector<int> pieces (v.begin(), v.begin() + r + 1);
				FOREACH(pieces, it) {
					int piece = *it;
					while (not (mx > piece)) {
						mx += mx-1;
						to_add ++;
					}
					mx += piece;
				}
				chmin(answer, to_add + to_remove);
			}
		}
		printf("Case #%d: %d\n", case_id, answer);
	}
}
