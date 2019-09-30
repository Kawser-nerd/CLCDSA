//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <inttypes.h>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#ifdef MAROON_LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

ll read(){
	ll i;
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

const int mod=1000000007;
const int inv2=500000004;
void add(int&a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}
void sub(int&a,int b){
	a-=b;
	if(a<0)a+=mod;
}
void mult(int&a,int b){
	a=ll(a)*b%mod;
}
const int Mmax=300;
int pow2[Mmax],powinv2[Mmax];
void Init(){
	pow2[0]=1;
	FOR(i,1,Mmax){
		pow2[i]=pow2[i-1];
		mult(pow2[i],2);
	}
	powinv2[0]=1;
	FOR(i,1,Mmax){
		powinv2[i]=powinv2[i-1];
		mult(powinv2[i],inv2);
	}
}

const int Nmax=15;
bool g[Nmax][Nmax];
int n;
int lose,buf[Nmax];
int mx[Nmax],way[Nmax][Nmax];
void waf(int i){
	ZERO(way[i]);
	mx[i]=-1;
	FOR(j,i+1,n)if(g[i][j]){
		way[i][buf[j]]++;
		chmax(mx[i],buf[j]);
	}
	int w=1;
	for(int k=0;k<=mx[i];k++)
		mult(w,pow2[way[i][k]]);
	for(int k=0;k<=mx[i]+1;k++){
		int t=way[i][k];
		mult(w,powinv2[t]);
		way[i][k]=w;
		mult(w,pow2[t]-1);
	}
}
void relka(int w){
	ZERO(way[0]);
	mx[0]=-1;
	int ps=0;
	FOR(j,2,n)if(g[0][j]){
		ps++;
		way[0][buf[j]]++;
		chmax(mx[0],buf[j]);
	}
	
	ZERO(way[1]);
	mx[1]=-1;
	FOR(j,2,n)if(g[1][j]){
		ps++;
		way[1][buf[j]]++;
		chmax(mx[1],buf[j]);
	}
	
	mult(w,pow2[ps]);
	
	int kk=min(mx[0],mx[1]);
	for(int k=0;k<=kk;k++){
		mult(w,powinv2[way[0][k]+way[1][k]]);
		add(lose,w);
		mult(w,pow2[way[0][k]]-1);
		mult(w,pow2[way[1][k]]-1);
	}
	mult(w,powinv2[way[0][kk+1]+way[1][kk+1]]);
	add(lose,w);
}
void dfs(int i,int w){
	if(i==1){
		relka(w);
	}else{
		waf(i);
		for(int k=0;k<=mx[i]+1;k++)if(way[i][k]){
			int t=w;
			buf[i]=k;
			mult(t,way[i][k]);
			dfs(i-1,t);
		}
	}
}

//done 1->2
signed main(){
	Init();
	n=read();
	int m=read();
	REP(_,m){
		int x=read()-1,y=read()-1;
		g[x][y]=1;
	}
	//REP(i,n)FOR(j,i+1,n)
	//	g[i][j]=1;
	g[0][1]=0;
	dfs(n-1,1);
	int ans=pow2[m];
	sub(ans,lose);
	cout<<ans<<endl;
}