#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define rep2(i,x,m) for(int i=x;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo = (int) 1e9;
string s1="welcome to code jam",s2;
int n1=19,n2;
int dp[20][600];
int calc(int i1,int i2){
	if(i1==n1)
		return 1;
	if(i2==n2)
		return 0;
	if(dp[i1][i2]!=-1)
		return dp[i1][i2];
	int ret=calc(i1,i2+1)%10000;
	if(s1[i1]==s2[i2])
		ret=(ret+calc(i1+1,i2+1))%10000;
	return dp[i1][i2]=ret;
}
int main() {
//#define SAMPLE
#ifndef SAMPLE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
#endif
#ifdef SAMPLE
	freopen("a.txt", "rt", stdin);
#endif
	int N;
	cin>>N;
	getline(cin,s2);
	rep(nn,N){
		getline(cin,s2);
		mem(dp,-1);
		n2=s2.sz;
		printf("Case #%d: %04d\n",nn+1,calc(0,0));
	}
	return 0;
}
