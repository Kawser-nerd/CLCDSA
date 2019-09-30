#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

char s[2000][2000];
int T,ti=0,n,m;
int in[2000][2000];
vector<int>g[20000];
bool vi[20000];
int np,ne;

void insert(int a,int b,int c,int d){
	int i=a*m+b,j=c*m+d;
	g[i].PB(j);
	g[j].PB(i);
}

void makeg(){
	for (int i=0;i<n*m;i++) g[i].clear();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++){
		if (s[i][j]=='-'){
			insert(i,(j+m-1)%m,i,(j+1)%m);
		}
		if (s[i][j]=='|'){
			insert((i+n-1)%n,j,(i+1)%n,j);
		}
		if (s[i][j]=='\\'){
			insert((i+n-1)%n,(j+m-1)%m,(i+1)%n,(j+1)%m);
		}
		if (s[i][j]=='/'){
			insert((i+1)%n,(j+m-1)%m,(i+n-1)%n,(j+1)%m);
		}
	}
}
void relax(int i){
	if (vi[i]) return;
	np++;
	vi[i]=true;
	for (int j=0;j<g[i].size();j++){
		ne++;
		relax(g[i][j]);
	}
}
int main(){
	for (scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%s",s[i]);
		makeg();
		memset(vi,false,sizeof(vi));
		int ans=1;
		for (int i=0;i<n*m;i++)if (!vi[i]){
			np=ne=0;
			relax(i);
			if (np*2!=ne) {ans=0;break;}
			ans=(ans*2)%1000003;
		}
		printf("Case #%d: %d\n",++ti,ans);
	}
    return 0;
}
