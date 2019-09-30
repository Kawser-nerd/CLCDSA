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

int N,M;
int a[110][10];
int p[10];

void main2(void){
	int i,j,ans=0;
	
	cin >> N >> M;
	REP(i,N) REP(j,M) cin >> a[i][j];
	
	REP(i,M) p[i] = i;
	do {
		int sum = 0;
		REP(i,N){
			int best = 0, tmp = 0;
			REP(j,M){
				tmp += a[i][p[j]];
				best = max(best, tmp);
			}
			sum += best;
		}
		ans = max(ans, sum);
	} while(next_permutation(p, p+M));
	
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
