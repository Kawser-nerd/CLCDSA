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

vector<string> dict;
int dp[4004][5]; // l -> min. #mismatches such that leftmost mismatch is at position l,l+1,l+2,l+3,(>=)l+4
int wrong[111];

void solve(int case_id, int n, string s) {
	for (int i=0;i<5;i++)dp[n][i] = 0;
	for (int l = n - 1; l >= 0; l --) {
		for (int i=0;i<5;i++)dp[l][i] = infInt;
		FOREACH(dict, it) {
			string const & part (*it);
			int le = len(part);
			int r = l + le - 1;
			if (not (r < n)) continue;
			int nwrong=0;
			for (int k=l; k<=r; k ++) {
				if (s[k] != part[k-l]) {
					if (nwrong > 0 and k-wrong[nwrong-1] < 5) goto nxt;
					wrong[nwrong++] = k;
				}
			}
			if (nwrong == 0) {
				for (int i=0;i<5;i++) {
					// leftmost mismatch is at position r+1+i
					chmin(dp[l][min(4, i + le)], dp[r+1][i]);
				}
			}
			else {
				int fstMismatch = wrong[0];
				int lstMismatch = wrong[nwrong-1];
				// find the least #changed such that condition dist>=5 is satisfied
				int opt = infInt;
				for (int i=0;i<5;i++) {
					if (r+1+i >= lstMismatch+5) {
						chmin(opt, nwrong + dp[r+1][i]);
					}
				}
				chmin(dp[l][min(4, fstMismatch - l)], opt);
			}
nxt:;
		}
	}
	printf("Case #%d: %d\n", case_id, *min_element(dp[0], dp[0] + 5));
}

int main() {
	ifstream dict_input ("garbled_email_dictionary.txt");
	string tmp;
	while (dict_input >> tmp) {
		dict.push_back(tmp);
	}
	int T;
	scanf("%d",&T);
	for (int case_id=1; case_id<=T; case_id++) {
		string s;
		cin >> s;
		solve(case_id, s.size(), s);
	}
}
