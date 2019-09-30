#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
typedef double D;
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define make(a) scanf("%d",&a)
//template<typename A> ma(A &a A b){if(a<b)a=b;}
//template<typename A> mi(A &a A b){if(a>b)a=b;}
#define MAX 10010
int n;
char kol[MAX];
vector<int> d[MAX];
bool x=0,wyn;
void clr(){
	R(i,n)d[i].clear();
	wyn = 0;
	x = 0;
}
LL has(int nr,int oj){
	LL ret = kol[nr];
	R(i,d[nr].size()){
		if(d[nr][i] != oj){
			ret*=has(d[nr][i],nr);
		}
	}
	return (ret*47231 + 1237) ^ 783126421878ll;
}
void spr(int nr,int oj){
	//printf("spr %d\n",nr);
	vector<pair<LL,int> > hs;
	R(i,d[nr].size())
	if(d[nr][i]!=oj)
		hs.PB(MP(has(d[nr][i],nr),d[nr][i]));
	sort(hs.begin(),hs.end());
	vector<int> todo;
	for(int i=0;i<hs.size();){
		if(hs[i].FI != hs[i+1].FI || i+1 ==  hs.size()){
			todo.PB(hs[i].SE);
			i++;
		}else
			i+=2;
	}
	if(todo.size()>1){
		wyn=0;
	}else
		R(i,todo.size())
			spr(todo[i],nr);
}
int dfs(int nr,int o){
	//printf("%d %d\n",nr,o);
	int roz = 1;
	R(i,d[nr].size()){
		if(d[nr][i]!=o)
			roz+=dfs(d[nr][i],nr);
	}
	if(2*roz>=n&&x==0){
	//	printf("xxx%d %d\n",nr,roz);
		x=1;
		if(2*roz==n){
			wyn = (has(nr,o) == has(o,nr));
			if(wyn == 0){
				wyn = 1;
				spr(nr,o);
				spr(o,nr);
			}
		}else{
			wyn = 1;
			vector<pair<LL,int> > hs;
			R(i,d[nr].size())
				hs.PB(MP(has(d[nr][i],nr),d[nr][i]));
			sort(hs.begin(),hs.end());
			vector<int> todo;
			for(int i=0;i<hs.size();){
				if(hs[i].FI != hs[i+1].FI || i+1 ==  hs.size()){
					todo.PB(hs[i].SE);
					i++;
				}else
					i+=2;
			}
			if(todo.size()>2){
				wyn=0;
			}else{
				R(i,todo.size())
					spr(todo[i],nr);
			}
		}
	}
	return roz;
}
void test(){
	static int tes=0;tes++;
	printf("Case #%d: ",tes);
	make(n);
	R(i,n)scanf(" %c",&kol[i]);
	clr();
	R(i,n-1){
		int a,b;
		make(a);a--;
		make(b);b--;
		d[a].PB(b);
		d[b].PB(a);
	}
	x=0;wyn=0;
	dfs(0,-1);
	puts(wyn?"SYMMETRIC":"NOT SYMMETRIC");
}
main(){
	int _;make(_);while(_--)test();
}