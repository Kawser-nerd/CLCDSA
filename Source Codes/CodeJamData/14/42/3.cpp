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

int N;
int a[1010];

void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) cin >> a[i];
	
	int ans = 0;
	REP(i,N){
		int L = 0, R = 0;
		REP(j,N) if(a[j] > a[i]) if(j < i) L++; else R++;
		ans += min(L, R);
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
