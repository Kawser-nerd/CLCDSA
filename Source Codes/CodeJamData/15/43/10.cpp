#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define pb push_back
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
int T,Cas,n;
bool ch(char p){
	return (p<='z'&&p>='a');
}
int go[110000][27];int tot;
int num[110000];int code;
vector<int>hav[2005];
namespace fl{
	int head[7005],np[210000],p[210000],flow[210000],tot;
	int S,T;
	void init(){
		memset(head,0,sizeof head);
		S=6001;T=6002;
		rep(i,1,tot){
			np[i]=p[i]=flow[i]=0;
		}
		tot=1;
	}
	void add(int u,int v,int w){
		//printf("%d %d %d\n",u,v,w);
		++tot;p[tot]=v;np[tot]=head[u];head[u]=tot;flow[tot]=w;
		++tot;p[tot]=u;np[tot]=head[v];head[v]=tot;
	}
	int q[7005],dis[7005];
	int BFS(){
		memset(dis,-1,sizeof dis);
		q[q[0]=1]=S;dis[S]=0;
		rep(i,1,q[0]){
			int x=q[i];
			for(int u=head[x];u;u=np[u])
			if(dis[p[u]]==-1)if(flow[u]){
				dis[p[u]]=dis[x]+1;
				q[++q[0]]=p[u];
			}
		}
		return dis[T];
	}
	int dinic(int x,int f){
		int ret=0;
		if(x==T)return f;
		for(int u=head[x];u;u=np[u])
		if(dis[p[u]]==dis[x]+1)
		if(flow[u]){
			int tmp=dinic(p[u],min(f,flow[u]));
			flow[u]-=tmp;flow[u^1]+=tmp;
			ret+=tmp;f-=tmp;
			if(!f)break;
		}
		if(!ret)dis[x]=-1;
		return ret;
	}
	int get(){
		int ans=0;
		while(BFS()!=-1){
			int tmp=dinic(S,1e9);
			ans+=tmp;
			//printf("%d\n",tmp);
		}
		return ans;
	}
};
void work(){
	fl::init();
	rep(i,1,tot)rep(j,0,25)go[i][j]=0;
	rep(i,1,tot)num[i]=0;
	rep(i,1,code)hav[i].clear();
	code=0;
	tot=1;
	scanf("%d",&n);
	rep(i,1,n){
		char p=getchar();
		while(!ch(p))p=getchar();
		while(1){
			int now=1;
			while(ch(p)){
				if(!go[now][p-'a'])go[now][p-'a']=++tot;
				now=go[now][p-'a'];
				p=getchar();
			}
			if(!num[now])num[now]=++code;
			hav[num[now]].pb(i);
			//printf("->%d %d\n",num[now],i);
			if(p!=' ')break;
			p=getchar();
		}
	}
	fl::add(fl::S,1,1e9);
	fl::add(2,fl::T,1e9);
	int ans=0;
	rep(i,1,code){
		if(hav[i].size()==1)continue;
		int nd1=(i-1)*2+n+1;
		int nd2=(i-1)*2+n+2;
		fl::add(fl::S,nd1,1);
		fl::add(nd2,fl::T,1);
		//printf("%d\n",hav[i].size()-1);
		rep(j,0,hav[i].size()-1){
			//printf("___%d %d\n",i,j);
			int x=hav[i][j];
			fl::add(nd1,x,1e9);
			fl::add(x,nd2,1e9);
		}
		ans--;
	}
	ans+=fl::get();
	printf("Case #%d: %d\n",Cas,ans);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for(Cas=1;Cas<=T;Cas++){
		work();
	}
	return 0;
}


