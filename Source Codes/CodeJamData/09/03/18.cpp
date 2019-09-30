#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <memory.h>
#include <cstdio>
#include <complex>
//#include <ctime>
//#include <hash_map>
using namespace std;
//using namespace stdext;


typedef unsigned int uint;
typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<double,double> PII;

#define sz size()
#define pb push_back
#define mp std::make_pair
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b);i>=_b;--i)
#define ABS(a) ((a)<0?-(a):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define HAS(v,k) ((v).find(k)!=(v).end())
#define CLR(a,v) memset((a),(v),sizeof(a))
#define CPY(a,b) memcpy((a),(b),sizeof(a))
#define sqr(a) ((a)*(a))
#pragma comment(linker,"/STACK:64000000")

int gcd(int a,int b) { return (!a)?b:gcd(b%a,a); }
LL lcm(int a, int b) { return a/gcd(a,b)*b; }
const LL MOD=10000;
const LD eps  = 1e-12;

#define PREV(a) ((a)&(a-1))
#define NEXT(a) ((a<<1)-PREV(a))
typedef int matrix[128][128];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int dp[2][512];
string s;
string F="welcome to code jam";

char ch[120000];
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	gets(ch);
	int TC; sscanf(ch,"%d",&TC);
	FOR(test,1,TC+1)
	{
		printf("Case #%d: ",test);
		gets(ch);
		s=string(ch);
		
		CLR(dp,0);
		FOR(i,0,s.sz) if (s[i]==F[0]) dp[0][i]=1;
		int cur=1;
		int old=0;
		FOR(t,1,F.sz)
		{
			CLR(dp[cur],0);
			FOR(i,0,s.sz) if (dp[old][i])
			{
				FOR(j,i+1,s.sz) if (s[j]==F[t]) dp[cur][j]=(dp[cur][j]+dp[old][i])%10000;
			}
			swap(old,cur);
		}
		int r=0;
		FOR(i,0,s.sz) r=(r+dp[old][i])%10000;
		printf("%04d\n",r);
	}

	
	
	return 0;	
}
