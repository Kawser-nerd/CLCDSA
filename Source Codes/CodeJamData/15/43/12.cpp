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

struct EDGE{
	int T,U;EDGE *Nxt,*Op;
	void init(const int S,const int T,const int U,EDGE *Op);
}*V[100001],*FV[100001],E[100001],*PE;

void EDGE::init(const int S,const int T,const int U,EDGE *Op){
	this->T=T;
	this->U=U;
	this->Op=Op;
	this->Nxt=V[S];
	V[S]=this;
}

void addedge(const int S,const int T,const int U){
	PE->init(S,T,U,PE+1);
	++PE;
	PE->init(T,S,0,PE-1);
	++PE;
}

int S,T,N,tot;
int Test;

char sss[40001];
map<string,int> Map;

int numMap,maxflow;

const int inf=0x3f3f3f3f;

int dist[10001];

int Q[10001],QH,QT;
bool in[10001];

inline bool modlabel(){
	REP_1(i,tot) dist[i]=inf,in[i]=0,FV[i]=V[i];
	dist[T]=0;
	QH=QT=-1;
	Q[++QT]=T;
	while(QH++!=QT){
		int x=Q[QH];
		if(x==S) return true;
		for(EDGE *ii=V[x];ii;ii=ii->Nxt){
			if(dist[ii->T]>dist[x]+1&&ii->Op->U){
				dist[ii->T]=dist[x]+1;
				Q[++QT]=ii->T;
			}
		}
	}
	return false;
}

int aug(const int x,const int limit){
	if(x==T) return limit;
	int ll=limit,kk;
	in[x]=1;
	for(;FV[x];FV[x]=FV[x]->Nxt){
		if(!in[FV[x]->T]&&dist[FV[x]->T]+1==dist[x]&&FV[x]->U){
			kk=aug(FV[x]->T,min(ll,FV[x]->U));
			ll-=kk;
			FV[x]->U-=kk;
			FV[x]->Op->U+=kk;
			if(!ll) return in[x]=0,limit;
		}
	}
	return limit-ll;
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&Test);
	REP_1(tt,Test){
		memset(V,0,sizeof(V));
		PE=E;
		scanf("%d",&N);
		numMap=1;
		Map.clear();
		gets(sss);
		REP_1(i,N){
			gets(sss);
			string S="";
			char *v=sss;
			while(*v){
				if(*v==' '){
					if(S!=""){
						if(Map.count(S)){
							int f=Map[S];
							addedge(i,N+f,inf);
							addedge(N+f+1,i,inf);
						}
						else{
							Map[S]=numMap;
							int f=numMap;
							addedge(N+f,N+f+1,1);
							numMap+=2;
							addedge(i,N+f,inf);
							addedge(N+f+1,i,inf);
						}
						S="";
					}
				}
				else{
					S+=*v;
				}
				++v;
			}
			if(S!=""){
				if(Map.count(S)){
					int f=Map[S];
					addedge(i,N+f,inf);
					addedge(N+f+1,i,inf);
				}
				else{
					Map[S]=numMap;
					int f=numMap;
					addedge(N+f,N+f+1,1);
					numMap+=2;
					addedge(i,N+f,inf);
					addedge(N+f+1,i,inf);
				}
			}
		}
		S=1,T=2;
		maxflow=0;
		tot=N+numMap-1;
		while(modlabel()){
			maxflow+=aug(S,inf);
		}
		printf("Case #%d: %d\n",tt,maxflow);
	}
	return 0;
}
