#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,d,p[1005],m[1005][1005];
int dp(int a, int b){
	if(a<=b) return 0;
	if(b==0) return 1000000;
	if(m[a][b]>0) return m[a][b];
	m[a][b]=min(dp(a-b,b)+1,dp(a-1,b-1));
	for(int x=b+1;x<=a/2;x++) m[a][b]=min(m[a][b],dp(x,b)+dp(a-x,b)+1);
	return m[a][b];
}
int main(){
	memset(m,0,sizeof(m));
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		int mp=1;
		scanf("%d",&d);
		for(int x=0;x<d;x++){
			scanf("%d",&p[x]);
			mp=max(mp,p[x]);
		}
		int ans=mp;
		for(int x=1;x<mp;x++){
			int cnt=x;
			for(int z=0;z<d;z++){
				cnt+=dp(p[z],x);
			}
			ans=min(cnt,ans);
		}
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}
