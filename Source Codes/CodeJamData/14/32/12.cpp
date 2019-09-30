//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x)((x)*(x))
#define clr(x)memset(x,0,sizeof(x))
#define clr1(x)memset(x,-1,sizeof(x))
#define clr80(x)memset(x,0x80,sizeof(x))
#define clr7F(x)memset(x,0x7F,sizeof(x))

#define ll long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int,int>
#define pip pair<int,pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>inline bool chkmin(T&a,T b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T&a,T b){return a<b?a=b,1:0;}
#define modadd(a,b,c)(((a)+(b))%(c))
#define modmul(a,b,c)((int)(((ll)(a)*(b))%(c)))

#define P 1000000007



#define getint(x){\
	char __next__char__;bool __nega__int__=0;\
	while(!isdigit(__next__char__=getchar())&&__next__char__!='-');\
	__next__char__=='-'?(x=0,__nega__int__=1):(x=__next__char__-48);\
	while(isdigit(__next__char__=getchar()))x=x*10+__next__char__-48;\
	if(__nega__int__)x=-x;\
}
#define getint2(x1,x2){getint(x1);getint(x2);}
#define getint3(x1,x2,x3){getint(x1);getint(x2);getint(x3);}
#define getint4(x1,x2,x3,x4){getint(x1);getint(x2);getint(x3);getint(x4);}
#define getint5(x1,x2,x3,x4,x5){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);}
#define getint6(x1,x2,x3,x4,x5,x6){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);getint(x6);}

char strr[200][200];
int f[26],b[26],e[26],l[200],s[26];
bool v[26];

bool check(int i){
	char*str=strr[i];
	clr(v);
	for(int j=l[i]-1;j--;){
		if(str[j]!=str[j+1]){
			if(v[str[j+1]-'a'])return 0;
			v[str[j+1]-'a']=1;
		}
	}
	return !v[str[0]-'a'];
}

int F[26];

int fa(int x){
	int r=F[x],y=r;
	while(r!=F[r])r=F[r];
	while((F[x]=r)!=(x=y))y=F[y];
	return r;
}

int run(){
	int n,ans=1;
	getint(n);
	clr(f);
	clr(b);
	clr(e);
	clr(s);
	for(int i=26;i--;)F[i]=i;
	for(int i=-1;++i!=n;){
		clr(v);
		scanf("%s",strr[i]);
		l[i]=strlen(strr[i]);
		char*str=strr[i];
		if(str[0]==str[l[i]-1]){
			e[str[0]-'a']++;
			ans=(ll)ans*e[str[0]-'a']%P;
		}else{
			int x=fa(str[0]-'a');
			int y=fa(str[l[i]-1]-'a');
			if(x==y)return 0;
			F[x]=y;
			if(f[str[0]-'a']++){
				return 0;
			}
			if(b[str[l[i]-1]-'a']++){
				return 0;
			}
		}
		for(int j=l[i];j--;)v[str[j]-'a']=1;
		for(int j=26;j--;)s[j]+=v[j];
	}
	for(int i=-1;++i!=n;){
		char*str=strr[i];
		if(!check(i)){
			return 0;
		}
		for(int j=l[i];j--;)
		if(str[j]!=str[l[i]-1]&&str[j]!=str[0]){
			if(s[str[j]-'a']>1)return 0;
		}
	}
	int q=0;
	for(int i=26;i--;){
		if((e[i]||b[i])&&F[i]==i)q++;
	}
	while(q){
		ans=(ll)ans*q%P;
		q--;
	}
	return ans;
}

int main(){
	int T;
	getint(T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: %d\n",t,run());
	}
	return 0;
}
