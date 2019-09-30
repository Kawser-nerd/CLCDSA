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

int N,X;
int a[10010];

void main2(void){
	int k,i;
	
	cin >> N >> X;
	REP(i,N) cin >> a[i];
	sort(a, a+N);
	
	int ans = N;
	for(k=0;2*k<=N;k++){
		bool good = true;
		REP(i,k) if(a[i] + a[2*k-1-i] > X) good = false;
		if(good) ans = min(ans, N-k);
	}
	
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
