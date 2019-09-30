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
int a[110];
int dp[110][300]; // pos, prev

void main2(void){
	int D,I,M,N,i,j,k;
	
	cin >> D >> I >> M >> N;
	REP(i,N) cin >> a[i];
	
	REP(i,N+1) REP(j,256) if(i == 0) dp[i][j] = 0; else dp[i][j] = INF;
	REP(i,N){
		// delete
		REP(j,256) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+D);
		// change
		REP(j,256) REP(k,256) if(abs(j-k) <= M) dp[i+1][k] = min(dp[i+1][k],dp[i][j]+abs(a[i]-k));
		// insert
		if(M != 0) REP(j,256) REP(k,256) dp[i+1][j] = min(dp[i+1][j],dp[i+1][k]+(abs(j-k)+M-1)/M*I);
	}
	
	int ans = INF;
	REP(i,256) ans = min(ans,dp[N][i]);
	gout << ans << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
