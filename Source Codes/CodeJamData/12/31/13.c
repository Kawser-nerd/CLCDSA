#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<string.h>

using namespace std;

#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))

int t;

int v[1010][1010],vis[1010][1010];
int c[1010];
int n;
bool found=false;

int dfs(int j){
	for(int k=0;k<n;k++){
				if(v[j][k]!=0 && vis[j][k]==0){
					vis[j][k]=1;
					c[k]++;
					if(c[k]>1){
						found=true;
						return 0;
					}
					if(dfs(k)<0) continue;
					else return 0;
				}
			}
	return -1;
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		found=false;
		memset(v,0,1010*1010*sizeof(int));
		cin>>n;
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			for(int k=0;k<temp;k++){
				int r;
				cin>>r;
				v[j][r-1]=1;
			}
		}
		for(int j=0;j<n;j++){
			memset(c,0,1010*sizeof(int));
			memset(vis,0,1010*1010*sizeof(int));
			if(dfs(j)<0) continue;
			else break;
		}
		if(found)
			cout<<"Case #"<<i<<": Yes"<<endl;
		else
			cout<<"Case #"<<i<<": No"<<endl;
	}
	return 0;
}
