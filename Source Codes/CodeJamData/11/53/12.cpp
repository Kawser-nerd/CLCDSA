#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define INF 1023456789
#define P 1000003

#define modp(x) (((x)%P+P)%P)

typedef long long ll;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

vector<int> adj[10101];
int deg[10101];
int xsize,ysize;
int chk[10101];
int degsum,vercnt;

int hoge(int x,int y){
	return y*xsize+x;
}

void saiki(int p){
	//printf("p=%d (%d)\n",p,adj[p].size());
	if(chk[p]==1)return;
	degsum+=deg[p];
	vercnt++;
	chk[p]=1;
	for(int i=0;i<adj[p].size();i++)saiki(adj[p][i]);
}

main(){
	int datasuu;
	scanf("%d ",&datasuu);
	for(int casenum=1;casenum<=datasuu;casenum++){
		printf("Case #%d: ",casenum);
			
		scanf("%d%d ",&ysize,&xsize);
		int n=xsize*ysize;
		for(int i=0;i<n;i++){adj[i].clear();deg[i]=0;}
		for(int j=0;j<ysize;j++){
			char buf[200];
			gets(buf);
			for(int i=0;i<xsize;i++){
				int p,q;
				if(buf[i]=='-'){
					p=hoge((i+xsize-1)%xsize,j);
					q=hoge((i+1)%xsize,j);
				}
				if(buf[i]=='|'){
					p=hoge(i,(j+ysize-1)%ysize);
					q=hoge(i,(j+1)%ysize);
				}
				if(buf[i]=='\\'){
					p=hoge((i+xsize-1)%xsize,(j+ysize-1)%ysize);
					q=hoge((i+1)%xsize,(j+1)%ysize);
				}
				if(buf[i]=='/'){
					p=hoge((i+xsize-1)%xsize,(j+1)%ysize);
					q=hoge((i+1)%xsize,(j+ysize-1)%ysize);
				}
				adj[p].push_back(q);
				adj[q].push_back(p);
				//printf("%d--%d\n",p,q);
				deg[p]++;
				deg[q]++;
			}
		}
		
		int ans=1;
		for(int i=0;i<n;i++)chk[i]=0;
		for(int i=0;i<n;i++){
			if(chk[i]==0){
				vercnt=degsum=0;
				saiki(i);
				//printf("%d %d\n",vercnt,degsum);
				if(degsum==vercnt*2)ans=modp(ans*2);
				else ans=0;
			}
		}
		printf("%d\n",ans);
	}
}