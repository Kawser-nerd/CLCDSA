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

int run(){
	int n,m,k;
	getint3(n,m,k);
	if(n>m)swap(n,m);//n<=m
	if(n<3){
		return k;
	}
	int ans=k;
	for(int i=2;i++!=n;){
		for(int j=2;j++!=m;){
			if(i*j<k)continue;
			for(int lt=0;lt<i&&lt<j;lt++){
				for(int rt=0;rt<i&&rt+lt<j;rt++){
					for(int lb=0;lb+lt<i&&lb<j;lb++){
						for(int rb=0;rb+rt<i&&lb+rb<j;rb++){
							#define calc(x) ((1+x)*x/2)
							chkmin(ans,i+i+j+j-lt-rt-lb-rb-4+max(0,k-i*j+(calc(lt)+calc(rt)+calc(lb)+calc(rb))));
						}
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int _=1;_<=t;_++){
		printf("Case #%d: %d\n",_,run());
	}
	return 0;
}
