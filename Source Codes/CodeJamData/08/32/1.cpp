#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
using namespace std;
#define maxlen 50
#define plus 0
#define minus 1
int nsc, sc;
char work[maxlen];
bool was[maxlen][maxlen][300];
long long dp[maxlen][maxlen][300];
int len;
long long cnt;
void init(){
	scanf(" %s ", work);
}
void perebor(int pos, long long num, int znak, long long res){
	if (pos==len){
		if (znak==minus) res-=num;
		else res+=num;
		if (res%2==0 || res%3==0 || res%5==0 || res%7==0){
			cnt++;
		}
	}
	else{
		perebor(pos+1, num*10+work[pos]-'0', znak, res);
		if (znak==plus)
			res+=num;
		else
			res-=num;
		perebor(pos+1, work[pos]-'0', plus, res);
		perebor(pos+1, work[pos]-'0', minus, res);
	}
}
void solvedp(int f, int t, int ost, int mod){
	int b;
	if (was[f][t][ost]) return;
	was[f][t][ost]=true;
	if (f==t){
		b=(work[f]-'0')%mod;
		if (b==ost){
			dp[f][t][ost]=1;
		}
		else
			dp[f][t][ost]=0;
	}
	else{
		dp[f][t][ost]=0;
		b=(work[f]-'0')%mod;
		int need;
		int i;
		for(i=f+1;i<=t;i++){
			need=(ost+mod-b)%mod;
			solvedp(i,t,need,mod);
			dp[f][t][ost]+=dp[i][t][need];
			need=(b+mod-ost)%mod;
			solvedp(i,t,need,mod);
			dp[f][t][ost]+=dp[i][t][need];
			b=(b*10+work[i]-'0')%mod;
		}
		if (b==ost)
			dp[f][t][ost]++;
	}
}
long long getdp(int f, int t, int b){
	memset(was, 0, sizeof(was));
	solvedp(f,t,0,b);
	return dp[f][t][0];
}
void solve(){
	len=strlen(work);
	cnt=0;
	cnt+=getdp(0, len-1, 2)+getdp(0, len-1, 3)+getdp(0, len-1, 5)+
		getdp(0, len-1, 7)-getdp(0, len-1, 6)-getdp(0, len-1, 10)-getdp(0, len-1, 14)-
		getdp(0, len-1, 15)-getdp(0, len-1, 21)-getdp(0, len-1, 35)+getdp(0, len-1, 30)+getdp(0, len-1, 70)+
		getdp(0, len-1, 105)+getdp(0, len-1, 42)-getdp(0, len-1, 210);
	printf("Case #%d: %lld\n", sc, cnt);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &nsc);
	for(sc=1; sc<=nsc; sc++){
		init();
		solve();
	}
	return 0;
}