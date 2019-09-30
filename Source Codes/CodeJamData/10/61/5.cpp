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

string s;
int dp[110][110];

void main2(void){
	int N,d,i,j,k;
	
	cin >> s;
	N = s.length();
	
	REP(i,N) REP(j,N) dp[i][j] = 0;
	for(d=1;d<N;d++) REP(i,N-d){
		j = i + d;
		for(k=i;k<=j;k++) dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
		dp[i][j] = max(dp[i][j],dp[i][j-1]);
		dp[i][j] = max(dp[i][j],dp[i+1][j]);
		if(s[i] == s[j]) dp[i][j] = max(dp[i][j],dp[i+1][j-1]+1);
	}
	
	int tmp = dp[0][N-1];
	int ans = 3 * N - 2 * tmp;
	gout << ans << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
