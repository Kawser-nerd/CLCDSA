#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
#define int long long
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
const int MOD=1e9+7;
int n,m;
signed main()
{
	n=read();m=read();
	if(abs(n-m)>1)return puts("0")&0;
	if(n<m)swap(n,m);
	if(n==m){
		int k=1;
		for(int i=1;i<=n;i++)k=k*i%MOD;
		printf("%lld",k*k%MOD*2%MOD);
	}else{
		int k=1;
		for(int i=1;i<=m;i++)k=k*i%MOD;
		printf("%lld",k*k%MOD*n%MOD);
	}
}