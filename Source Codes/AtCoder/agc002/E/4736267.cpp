//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
// #include<unordered_map>
using namespace std;
int bin[40],lg[1<<21];
namespace mine
{
	typedef long long ll;
	#define double long double
	const int INF=0x3f3f3f3f;
	const ll LLINF=0x3f3f3f3f3f3f3f3fll;
	ll qread()
	{
		ll ans=0;char c=getchar();int f=1;
		while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) {num=-num;putchar('-');}
		if(num>9) write(num/10);
		putchar('0'+num%10);
	}
	void writeln(int num){write(num);puts("");}
	#define FR first
	#define SE second
	#define MP make_pair
	#define pr pair<int,int>
	#define PB push_back
	#define vc vector
	void chmax(int &x,const int y) {x=x>y?x:y;}
	void chmin(int &x,const int y) {x=x<y?x:y;}
	const int MAX_N=1e5+10;
	const int MOD=1e9+7;
	void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

	int a[MAX_N];
	void main()
	{
		int n=qread();for(int i=1;i<=n;i++) a[i]=qread();
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		for(int x=1;x<=n;x++)
			if(x+1>a[x+1])
			{
				int up=(a[x]-x),right=0;
				while(x+right+1<=n and x<=a[x+right+1]) right++;
				int now;
				if(up==0 and right==0) now=0;
				else if(up==0) now=right&1;
				else if(right==0) now=up&1;
				else now=(((up-1)&1)==0 or ((right-1)&1)==0);
				puts(now?"First":"Second");
				break;
			}
	}
};
int main()
{
	srand(time(0));
	bin[0]=1;for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
	lg[1]=0;for(int i=2;i<(1<<21);i++) lg[i]=lg[i>>1]+1;
	mine::main();
}