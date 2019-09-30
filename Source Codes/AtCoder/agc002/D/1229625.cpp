#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m,q,m_;
int a[100001],b[100001];
int x[100001],y[100001],z[100001];
int res[100001];
int par[100001],rank2[100001];
int cnt[100001];
vector<int> vec[1000001];
int l[1000001],r[1000001];

int find(int x){
	if(par[x]==x)return x;
	return (par[x]=find(par[x]));
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank2[x]<rank2[y]){
		par[x]=y;
		cnt[y]+=cnt[x];
	}else{
		par[y]=x;
		cnt[x]+=cnt[y];
		if(rank2[x]==rank2[y])rank2[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		x[i]--;
		y[i]--;
		vec[0].push_back(i);
	}
	l[0]=-1,r[0]=m-1;
	m_=1;
	while(m_<m)m_*=2;
	for(int i=0;i<m_;i++){
		l[i*2+1]=l[i];
		r[i*2+1]=(l[i]+r[i])/2;
		l[i*2+2]=(l[i]+r[i])/2;
		r[i*2+2]=r[i];
	}
	int now=0;
	int nex=1;
	int len=1;
	bool flag=false;
	memset(res,-1,sizeof(res));
	for(int i=0;i<30;i++){
		flag=false;
		for(int j=0;j<n;j++){
			par[j]=j;
			rank2[j]=0;
			cnt[j]=1;
		}
		for(int j=0;j<m;j++){
			if(!same(a[j],b[j])){
				unite(a[j],b[j]);
			}
			while((l[now]+r[now])/2<=j && now<nex){
				if(l[now]+1==r[now]){
					for(int k=0;k<vec[now].size();k++){
						if(res[vec[now][k]]==-1)res[vec[now][k]]=r[now];
					}
				}else{
					for(int k=0;k<vec[now].size();k++){
						int va=vec[now][k];
						flag=true;
						if(!same(x[va],y[va])){
							int cc=cnt[find(x[va])]+cnt[find(y[va])];
							if(cc>=z[va]){
								vec[now*2+1].push_back(va);
							}else{
								vec[now*2+2].push_back(va);
							}
						}else{
							int cc=cnt[find(x[va])];
							if(cc>=z[va]){
								vec[now*2+1].push_back(va);
							}else{
								vec[now*2+2].push_back(va);
							}
						}
					}
				}
				now++;
			}
		}
		if(!flag)break;
		now=nex;
		len=len*2;
		nex=now+len;
	}
	for(int i=0;i<q;i++){
		printf("%d\n",res[i]+1);
	}
	return 0;
}