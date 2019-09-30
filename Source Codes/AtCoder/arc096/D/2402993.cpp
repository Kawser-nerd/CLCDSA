#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
typedef long long LL;
//typedef __int128 LL;
using namespace std;
const int maxn=55;
const int maxm=maxn*maxn*maxn;
const int IINF=1E9+77;
const LL INF=1E18+77;

int N,X,D,M[maxn],P[maxn],T;
LL DP[2][maxm];


struct NODE{
	int v;
	LL s;
	int c;
	bool operator <(const NODE &o)const{
		if(v*o.s != o.v*s){
			return v*o.s > o.v*s;
		}else{
			return s<o.s;
		}
	}
}nodes[maxn];

struct EDGE{
	int to,next;
}edges[maxn];
int cEdge=1,head[maxn];
void addEdge(int from,int to){
	edges[cEdge]=(EDGE){to,head[from]};
	head[from]=cEdge++;
}

void dfs(int u){
	nodes[u]=(NODE){1,M[u],u==1?IINF:D};
	for(int k=head[u];k;k=edges[k].next){
		int v=edges[k].to;
		dfs(v);
		nodes[u].v+=nodes[v].v;
		nodes[u].s+=nodes[v].s;
	}
}

pair<LL,int> Q[maxn][maxn*maxn];
int qh[maxn],qr[maxn];

void push(int x,LL v,int p){
	while(qh[x]!=qr[x] && v <= Q[x][qr[x]-1].first) --qr[x];
	Q[x][qr[x]++]=make_pair(v,p);
}

LL query(int x,int p){
	while(qh[x]!=qr[x] && Q[x][qh[x]].second < p) ++qh[x];
	return Q[x][qh[x]].first;
}

int main(){
	scanf("%d%d%d",&N,&X,&D);
	scanf("%d",M+1);
	for(int i=2;i<=N;++i){
		scanf("%d%d",M+i,P+i);
		addEdge(P[i],i);
	}

	dfs(1);

	//for(int i=1;i<=N;++i) cerr<<nodes[i].v<<" "<<nodes[i].s<<" "<<nodes[i].c<<endl;

	for(int i=1;i<maxm;++i){
		DP[T][i]=INF;
		//if(i<9) cerr<<"DP["<<1<<"]["<<i<<"]="<<DP[T][i]<<endl;
	}

	for(int i=1;i<=N;++i){
		T^=1;
		int v=nodes[i].v;
		LL s=nodes[i].s;
		int c=min(nodes[i].c,maxn);
		nodes[i].c-=c;
		for(int j=0;j<maxm;++j){
			push(j%v,DP[T^1][j]-(j/v)*s,j/v);
			DP[T][j]=query(j%v,(j/v)-c)+(j/v)*s;
			//if(j<9) cerr<<"DP["<<i<<"]["<<j<<"]="<<DP[T][j]<<endl;
		}
		memset(qh,0,sizeof(qh));
		memset(qr,0,sizeof(qr));
		//cerr<<endl;
	}

	for(int i=maxm-2;i>=0;--i){
		DP[T][i]=min(DP[T][i],DP[T][i+1]);
		//if(i<9) cerr<<"DP["<<i<<"]="<<DP[T][i]<<endl;
	}

	//cerr<<"??"<<endl;

	sort(nodes+1,nodes+N+1);
	int p=1,V=0,ans=0;
	LL S=0;
	for(int i=maxm-1;i>=0;--i){
		while(true){
			while(p<=N && !nodes[p].c) ++p;
			if(p<=N && DP[T][i]+S+nodes[p].s <= X){
				int t=(X-DP[T][i]-S)/nodes[p].s;
				if(t>nodes[p].c) t=nodes[p].c;

				V+=nodes[p].v*t;
				S+=nodes[p].s*t;
				nodes[p].c-=t;
			}else{
				break;
			}
		}
		if(DP[T][i]+S <= X){
			//cerr<<i<<":"<<DP[T][i]<<"  S:"<<S<<endl;
			//cerr<<"dp["<<i<<"]="<<DP[T][i]<<endl;
			//if(i+V > ans) cerr<<":"<<i<<" "<<V<<endl;
			ans=max(ans,i+V);
		}
	}

	printf("%d\n",ans);
}