#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

#define INF (1<<29)

int dp[(1<<12)][20],M[(1<<12)],cost[(1<<12)];

void main2(void){
	int P,i,j;
	
	scanf("%d",&P);
	REP(i,(1<<P)) {scanf("%d",&M[i]); M[i] = P - M[i];}
	int tmp = (1<<P);
	for(i=P-1;i>=0;i--){
		tmp -= (1<<i);
		REP(j,(1<<i)) scanf("%d",&cost[tmp+j]);
	}
	
	REP(i,(1<<P)) REP(j,20) dp[i][j] = INF;
	for(i=(1<<P);i>=1;i--) REP(j,20){
		int half = (1<<(P-1));
		if(i >= half){
			int Mmax = max(M[(i-half)*2],M[(i-half)*2+1]);
			if(j >= Mmax) dp[i][j] = min(dp[i][j],0);
			if(j+1 >= Mmax) dp[i][j] = min(dp[i][j],cost[i]);
		} else {
			dp[i][j] = min(dp[i][j], dp[i*2][j] + dp[i*2+1][j]);
			int j2 = min(j+1,19);
			dp[i][j] = min(dp[i][j], dp[i*2][j+1] + dp[i*2+1][j+1] + cost[i]);
		}
	}
	
	printg("%d\n",dp[1][0]);
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
