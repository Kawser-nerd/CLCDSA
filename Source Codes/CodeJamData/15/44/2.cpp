#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

int H,W;
int typeA[5],typeB[5];
ll dpA[110],dpB[110];

ll func(int H, int W, int rot){
	int i,j;
	
	REP(i,5) typeA[i] = typeB[i] = 0;
	typeB[2] = 1;
	typeA[1] = 1;
	if(W % 6 == 0 && rot % 6 == 0) typeA[2] = 9; else if(W % 3 == 0 && rot % 3 == 0) typeA[2] = 3;
	if(W % 4 == 0 && rot % 4 == 0) typeA[3] = 4;
	
	REP(i,H+1) dpA[i] = dpB[i] = 0;
	dpA[0] = dpB[0] = 1;
	
	for(i=1;i<=H;i++) for(j=1;j<=3;j++) if(j <= i){
		dpA[i] = (dpA[i] + typeA[j] * dpB[i-j]) % MOD;
		dpB[i] = (dpB[i] + typeB[j] * dpA[i-j]) % MOD;
	}
	
	return (dpA[H] + dpB[H]) % MOD;
}

void main2(void){
	int i,j;
	
	cin >> H >> W;
	
	ll ans = 0;
	REP(i,W) ans = (ans + func(H, W, i)) % MOD;
	while(ans % W != 0) ans += MOD;
	ans /= W;
	
	cout << ans << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
