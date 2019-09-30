#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<iostream>
#define N 1200
using namespace std;
const int mo=1000000007;
string a[N];
int fac[N],ans,T,n,i,bo[N],all,tail,head,mid,j,k,tim,num;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	fac[0]=1;
	for(i=1;i<=100;++i)fac[i]=1ll*fac[i-1]*i%mo;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)cin>>a[i];
		memset(bo,0,sizeof(bo));
		ans=1;
		num=0;
		tim++;
		printf("Case #%d: ",tim);
		for(char c='a';c<='z';++c){
			head=tail=mid=-1;
			all=0;
			for(i=1;i<=n;++i)if(!bo[i]){
				int l=a[i].length();
				for(j=0;j<l;++j)if(a[i][j]!=c)break;
				if(j==l)all++,bo[i]=1;
				else{
					for(k=l-1;k>=0;--k)if(a[i][k]!=c)break;
					bool f=0;
					for(int x=j;x<=k;++x)if(a[i][x]==c)f=1;
					if(j && !f && k==l-1){
						if(head!=-1)goto fail;
						head=i;
					}else
					if(!j && !f && k!=l-1){
						if(tail!=-1)goto fail;
						tail=i;
					}else if(!j && !f && k==l-1)continue;
					else if(!j && k==l-1 && f){
						if(mid!=-1)goto fail;
						mid=i;
					}else goto fail;
				}
			}
			if(mid!=-1 && (head!=-1 || tail!=-1 || all))goto fail;
			if(head==-1 && tail==-1 && mid==-1 && all)num++;
			if(head!=-1 && tail!=-1){
				a[++n]=a[tail]+a[head];
				bo[tail]=bo[head]=1;
			}
			ans=1ll*ans*fac[all]%mo;
		}
		for(i=1;i<=n;++i)if(!bo[i])num++;
		for(i=1;i<=num;++i)ans=1ll*ans*i%mo;
		printf("%d\n",ans);
		continue;
		fail:;
		printf("0\n");
	}
}
				
