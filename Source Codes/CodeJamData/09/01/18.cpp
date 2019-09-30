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
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

char ch[120000];
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int L,N,M;
	scanf("%d%d%d",&L,&N,&M);

	vector<string> w;
	FOR(i,0,N)
	{
		scanf("%s",ch);
		w.pb(string(ch));
	}

	FOR(t,0,M)
	{
		scanf("%s",ch);
		string s(ch);

		int r=0;
		int p=0;
		int can[20][26]={0};
		FOR(j,0,L)
		{
			if (p==s.sz) {p=s.sz-1; break;}
			if (s[p]!='(') can[j][s[p++]-'a']=1;
			else
			{
				++p;
				while(s[p]!=')') can[j][s[p++]-'a']=1;
				++p;
			}
		}
		if (p!=s.sz) r=0;
		else
		{
			FOR(i,0,N)
			{
				int ok=1;
				FOR(j,0,L)
					if (!can[j][w[i][j]-'a']) {ok=0; break;}
				if (ok)++r;
			}
		}
		printf("Case #%d: %d\n",t+1,r);
	}

	
	
	return 0;	
}
