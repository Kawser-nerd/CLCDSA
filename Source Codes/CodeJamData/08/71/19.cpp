#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

#define MAXN 2000

int n;
map<string,int> mapa;
int lst[MAXN][MAXN];
int deg[MAXN];
int resp[MAXN];
bool mrk[MAXN];

int ord[MAXN][MAXN];

void calc(int v){
	if(mrk[v]) return ;
	mrk[v] = true;
	
	int i,j;
	int ret;
	
	if(deg[v] == 0){
		resp[v] = 1;
		return ;
	}
	
	for(i=0;i<deg[v];i++){
		calc(lst[v][i]);
		ord[v][i] = 1+deg[lst[v][i]];
	}
	
	ret = 0;
	
	sort(&ord[v][0],&ord[v][deg[v]]);
	reverse(&ord[v][0],&ord[v][deg[v]]);
	
	ret = ord[v][0];
	
	for(i=1;i<deg[v];i++){
		ret = max(ret,ord[v][i]+i);
	}
	
	ret = max(ret,1+deg[v]);
	
	resp[v] = ret;
	
}

int coloca(string s){
	if(mapa.find(s) == mapa.end()){
		deg[n] = 0;
		resp[n] = 1;
		mrk[n] = false;
		mapa[s] = n;
		n++;
		return n-1;
	}
	return mapa[s];
}

int main(){
	
	int t,lp;
	int a,b,c;
	int i,j,k,h;
	int ret;
	string mix,hlp;
	
	cin >> t;
	
	for(lp=1;lp<=t;lp++){
		cin >> k;
		mapa.clear();
		n = 0;
		
		for(i=0;i<MAXN;i++) deg[i] = 0;
		
		for(i=0;i<k;i++){
			cin >> mix;
			a = coloca(mix);
			cin >> h;
			for(j=0;j<h;j++){
				cin >> hlp;
				if(hlp[0] >= 'a' && hlp[0] <= 'z') continue;
				b = coloca(hlp);
				lst[a][deg[a]++] = b;
			}
		}
		
		ret = 1;
		
		//printf("%d\n",n);
		
		for(i=0;i<n;i++){
			//printf("%d %d\n",deg[i],ret);
			calc(i);
			ret = max(ret,resp[i]);
			//printf("%d\n",resp[i]);
		}
		
		printf("Case #%d: %d\n",lp,ret);
		
	}
	
	return 0;
	
}

