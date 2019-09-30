#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	ll dp[100][3]={};
	ll N;
	cin>>N;
	dp[64][0]=1;
	dp[64][1]=0;
	dp[64][2]=0;
	for(int i=63;i>=0;i--){
		if((N>>i)&1){
			dp[i][0]=(dp[i+1][0])%MOD;
			dp[i][1]=(dp[i+1][0]+dp[i+1][1])%MOD;
			dp[i][2]=(3*dp[i+1][2]+2*dp[i+1][1])%MOD;

		}
		else{
			dp[i][0]=(dp[i+1][0]+dp[i+1][1])%MOD;
			dp[i][1]=(dp[i+1][1])%MOD;
			dp[i][2]=(3*dp[i+1][2]+dp[i+1][1])%MOD;
		}
	}
	cout<<(dp[0][0]+dp[0][1]+dp[0][2])%MOD<<endl;
	return 0;
}