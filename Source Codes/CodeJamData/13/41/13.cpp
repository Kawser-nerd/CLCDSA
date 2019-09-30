#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std; typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

#define MOD 1000002013

int T;
int N, M, S[1000], D[1000], P[1000];

i64 calc(int D)
{
	if(D<0) return calc(-D);
	return ((i64)D * N - (i64)D * (D-1) / 2) % MOD;
}

int main()
{
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%d%d", &N, &M);
		for(int i=0;i<M;i++) scanf("%d%d%d", S+i, D+i, P+i);

		i64 epc = 0;
		for(int i=0;i<M;i++) epc += (calc(D[i] - S[i]) * P[i]) % MOD;
		epc %= MOD;

		vector<pair<i64, i64> > v1, v2;
		for(int i=0;i<M;i++){
			v1.push_back(make_pair((i64)S[i], (i64)P[i]));
			v2.push_back(make_pair((i64)D[i], (i64)P[i]));
		}
		sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());

		i64 ret = 0;
		for(int i=0;i<M;i++){ //v2[i]
			for(int j=M-1;j>=0;j--) if(v1[j].first <= v2[i].first){
				i64 dec = min(v1[j].second, v2[i].second);
				ret += (calc(v2[i].first - v1[j].first) * dec) % MOD;
				ret %= MOD;
				v1[j].second -= dec;
				v2[i].second -= dec;

				if(v2[i].second==0) break;
			}
		}

		printf("Case #%d: %lld\n", t, (epc - ret + MOD) % MOD);
	}

	return 0;
}
