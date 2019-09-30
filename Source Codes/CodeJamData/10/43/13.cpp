#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=2010;
const int inf=0x1fffffff;
int s[N],x1[N],x2[N],y1[N],y2[N];

int anc(int x){
	if (s[x]!=x) s[x]=anc(s[x]);
	return s[x];
}
int main(){
	int tt,cas,i,j,n;
	scanf("%d",&tt);
	for (cas=1;cas<=tt;cas++){
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			s[i]=i;
		for (i=1;i<=n;i++)
			scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++){
				if (x2[i]>=x1[j]-1&&x2[j]>=x1[i]-1)
					if (y2[i]>=y1[j]-1&&y2[j]>=y1[i]-1){
						if (x2[i]+1==x1[j]&&y2[i]+1==y1[j])
							continue;
						if (x2[j]+1==x1[i]&&y2[j]+1==y1[i])
							continue;
						s[anc(i)]=anc(j);
					}
			}
		int ans=0;
		for (i=1;i<=n;i++)
			s[i]=anc(i);
		for (i=1;i<=n;i++)
			if (s[i]==i){
				int maxx=0,maxy=0;
				for (j=1;j<=n;j++)
					if (s[j]==i){
						maxx=max(x2[j],maxx);
						maxy=max(y2[j],maxy);
					}
				for (j=1;j<=n;j++)
					if (s[j]==i)
						ans=max(ans,abs(maxx-x1[j])+abs(maxy-y1[j]));
			}
		printf("Case #%d: %d\n",cas,ans+1);
	}
	return 0;
}
