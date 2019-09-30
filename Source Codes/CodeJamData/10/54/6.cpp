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

typedef long long ll;
#define MOD 1000000007ll
ll C[80][80],F[80];

int L,B,d[80];
ll dp[80][80][80]; // pos, sum, nonzero
int dp2[2][80][3000]; // pos, cnt, sum
ll a[80][80][3000]; // nonzero1, nonzero2, sum

void pre(void){
	int i,j;
	
	REP(i,80) REP(j,i+1){
		if(j == 0 || j == i) C[i][j] = 1;
		else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	
	F[0] = 1;
	for(i=1;i<80;i++) F[i] = F[i-1] * i % MOD;
}

void main2(void){
	int i,j,k,j2,k2;
	
	ll N;
	cin >> N >> B;
	L = 0;
	while(N > 0) {d[L] = N % B; N /= B; L++;}
	
	REP(i,2) REP(j,80) REP(k,3000) dp2[i][j][k] = 0;
	dp2[1][0][0] = 1;
	for(i=1;i<B;i++){
		int cur = i%2, next = (i+1)%2;
		REP(j,80) REP(k,3000) dp2[next][j][k] = 0;
		REP(j,80) REP(k,3000) if(dp2[cur][j][k] > 0){
			dp2[next][j][k] = (dp2[next][j][k] + dp2[cur][j][k]) % MOD;
			dp2[next][j+1][k+i] = (dp2[next][j+1][k+i] + dp2[cur][j][k]) % MOD;
		}
	}
	
	REP(i,80) REP(j,80) REP(k,3000) a[i][j][k] = 0;
	REP(i,B+1) REP(j,B+1) if(i <= j) REP(k,3000){
		a[i][j][k] = dp2[B%2][j][k] * C[j][i] % MOD * F[i] % MOD;
		if(i > 0) a[i][j][k] = (a[i][j][k] + dp2[B%2][j-1][k] * C[j-1][j-i] % MOD * F[i] % MOD) % MOD;
	}
	
	REP(i,80) REP(j,80) REP(k,80) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	REP(i,L) REP(j,B+1) REP(k,B+1) if(dp[i][j][k] > 0) REP(j2,B+1){
		int x = j*B + d[L-1-i] - j2;
		if(x >= 0 && x < 3000) for(k2=k;k2<=B;k2++) dp[i+1][j2][k2] = (dp[i+1][j2][k2] + dp[i][j][k] * a[k][k2][x]) % MOD;
	}
	
	ll ans = 0;
	REP(i,B+1) ans = (ans + dp[L][0][i]) % MOD;
	gout << ans << endl;
}

int main(void){
	pre();
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
