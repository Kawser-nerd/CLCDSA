#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T Mul(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Pow(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=Mul(F1,x,P);
		}
		x=Mul(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdateMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

#define MaxBuffer 20000000
class ReadBuffer{
	private:
	char buff[MaxBuffer];
	char *buf;
	public:
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
		buf=buff;
	}
	template<class T>
	bool readInteger(T &x)
	{
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag;
		flag=0;
		if(*buf=='-') flag=true;
		else x=*buf-'0';
		while(isdigit(*++buf)) x=x*10+*buf-'0';
		if(flag) x=-x;
		return true;
	}
	template<class T>
	bool readFloat(T &x)
	{
		long double nowpos=0.1;
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag,decimal;
		decimal=flag=0;
		if(*buf=='-') flag=true,++buf;
		else if(*buf=='.') decimal=true;
		while(isdigit(*buf)||*buf=='.')
		{
			if(*buf=='.') decimal=true;
			else
			{
				if(decimal)
				{
					x+=nowpos*(*buf-'0');
					nowpos*=0.1;
				}
				else
				{
					x=x*10+*buf-'0';
				}
			}
			++buf;
		}
		return true;
	}
	bool readChar(char c)
	{
		if(*buf==0) return 0;
		return c=*buf++,1;
	}
	bool readString(char *s)
	{
		while(*buf&&isspace(*buf)) ++buf;
		if(!*buf) return false;
		while(!isspace(*buf)) *s++=*buf++;
		*s++=0;
		return true;
	}
	int countSpacetonext(){
		int total=0;
		while(*buf&&*buf==' ') ++total,++buf;
		return total;
	}
	bool splitBycharactor(char *s,char Split='\n'){
		while(*buf&&*buf!=Split) *s++=*buf++;
		*s++=0;
		return *buf!=0;
	}
};
int G[101][101];
int U[201][201];
int dist[201];
int Q[201],QH,QT;
int now[201];
int T,N,M,K;
bool in[201];

void getdist(){
	for(int i=0;i<N;++i) dist[i]=N+1;
	dist[N-1]=0;
	QH=QT=-1;
	Q[++QT]=N-1;
	while(QH++!=QT){
		int x=Q[QH];
		for(int i=0;i<N;++i) if(G[i][x]&&dist[i]>dist[x]+1){
			dist[i]=dist[x]+1;
			Q[++QT]=i;
		}
	}
}

bool modlabel(){
	for(int i=0;i<N;++i) dist[i]=N+1,in[i]=0,now[i]=0;
	dist[N-1]=0;
	QH=QT=-1;
	Q[++QT]=N-1;
	while(QH++!=QT){
		int x=Q[QH];
		if(!x) return true;
		for(int i=0;i<N;++i) if(U[i][x]&&dist[i]>dist[x]+1){
			dist[i]=dist[x]+1;
			Q[++QT]=i;
		}
	}
	return false;
}

int aug(int x,int lim){
	if(x==N-1) return lim;
	int kk,ll=lim;
	in[x]=1;
	for(;now[x]<N;++now[x]){
		if(U[x][now[x]]&&dist[now[x]]+1==dist[x]){
			kk=aug(now[x],min(ll,U[x][now[x]]));
			U[x][now[x]]-=kk,U[now[x]][x]+=kk;
			ll-=kk;
			if(!ll) return in[x]=0,lim;
		}
	}
	return lim-ll;
}



int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	REP_1(tt,T){
		scanf("%d%d%d",&N,&M,&K);
		memset(G,0,sizeof(G));
		memset(U,0,sizeof(U));
		while(M--){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x][y]=G[y][x]=1;
		}
		getdist();
		printf("Case #%d: ",tt);
		if(K==0) printf("%d\n",dist[0]);
		else{
			int ans=dist[0];
			--K;
			for(int i=1;i<N-1;++i){
				U[i*2-1][i*2]=1;
			}
			for(int i=0;i<N-1;++i) for(int j=1;j<N;++j) if(G[i][j]&&dist[i]==dist[j]+1){
				U[i*2][j*2-1]=101000;
			}
			N=(N-1)*2;
			int maxflow=0;
			while(modlabel()){
				maxflow+=aug(0,100000);
			}
			if(maxflow>K) printf("%d\n",ans+1);
			else printf("%d\n",ans+2);
		}
	}
	return 0;
}
