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
#define MAX 110
int n;
char t2[MAX][MAX];
bool t[MAX][MAX];
int a;
bool cz[MAX],cz2[MAX];
int os2,os;
bool kon;
void clr(){
	R(i,n){
		cz[i] = 0;
		cz2[i] = 0;
	}
	kon = 0;
}
void dfs(int nr){
	if(cz[nr])return;cz[nr] = 1;
	R(i,n)if(t[nr][i] && cz2[i] == 0)dfs(i);
}
bool dod(int nr){
	if(nr == a){
		if(!t[nr][os])return 0;
		R(i,n)if(cz2[i]==0&&t[a][i]==0)return 0;
		printf(" %d",nr);
		R(i,n)if(i!=a&&cz2[i]==0)printf(" %d",i);
		kon = 1;
		return 1;
	}
	if(t[nr][os])os2 = nr;else os2 = os;
	cz2[nr] = 1;
	R(i,n)cz[i] = 0;
	dfs(a);
	R(i,n)if(cz[i] == 0 && cz2[i] == 0 && t[os2][i] == 0){
		cz2[nr] = 0;
		return 0;
	}
	printf(" %d",nr);
	/*vector<int> pom;
	R(i,n)if(cz[i] == 0 && cz2[i] == 0){
		cz2[i] = 1;
	}
	int j = 0;
	R(i,n)if(cz[i] == 0 && cz2){
		
	}*/
	os = os2;
	return 1;
}
void test(){
	static int tes=0;tes++;
	printf("Case #%d:",tes);
	
	make(n);make(a);
	clr();
	R(i,n){
		scanf(" %s",t2[i]);
		R(j,n)t[i][j] = (t2[i][j] != 'N');
	}
	/*if(tes == 46){
		printf("%d %d\n",n,a);
		R(i,n)printf("%s\n",t2[i]);
	}
	return;*/
	dfs(a);
	R(i,n){
		if(cz[i] == 0){
			puts(" IMPOSSIBLE");
			return;
		}
	}
	bool pom = 1;
	while(!kon){
		R(j,n){
			if(cz2[j]==0){
				if(pom)os = j;
				if(dod(j)){
					break;
				}
			}
		}
		pom = 0;
	}
	puts("");
}
main(){
	int _;make(_);while(_--)test();
}