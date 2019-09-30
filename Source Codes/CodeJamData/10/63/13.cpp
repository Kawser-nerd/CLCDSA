#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define MP make_pair
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;

int k, C;
int F[22][4][33][33][33];

int can(int k, int C,int s1, int s2, int s3) {
	if(k == 0) return 1;
	int &ret = F[k][C][s1][s2][s3];
	
	if(ret != -1) return ret;
	
	ret = 1;
	
	for(int cur=1;cur<=C;++cur) {
		bool ok = false;
		
		Rep(t1,4) Rep(t2,4) Rep(t3,4) if(t1 * 1 + t2 * 2 + t3 * 3 == cur) {
			if(t1 <= s1 && t2 <= s2 && t3 <= s3) {
				if(can(k-1,C,s1-t1,s2-t2,s3-t3)) {
					ok = true;
					goto here;
				}				
			}
		}
		
		here: ;
		
		if(!ok) {
			return ret = 0;
		}
		
	}
	
	return ret;
}

int main() {
	int ntest;
	scanf("%d", &ntest);
	memset( F, -1, sizeof(F));
	For(test,1,ntest) {
		cerr << "test = " << test << endl;
		scanf("%d%d",&k,&C);
		
		int best = 1000000;
		
		Rep(s1,30) Rep(s2,30) Rep(s3,30) {
			if(can(k, C, s1, s2, s3)) {
				best <?= s1 + s2 + s3;
			}
		}
		
		int res = best;
		
		printf("Case #%d: ", test);
		printf("%d\n", res);
		fflush(stdout);
	}
    return 0;
}
