#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<stdio.h>
#include<cstring>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=202;
int ca,ti,x[maxn],y[maxn],m[maxn],f[maxn][maxn],i,j,k,ans,tmp,arr,n;
bool found;
int main(){
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n)
			cin>>x[i]>>y[i]>>m[i];
		memset(f,255,sizeof(f));
		fr(i,1,n){
			tmp=max(abs(x[i]),abs(y[i]))*100;
			if(tmp<=m[i]+1000)
				f[i][1]=max(tmp,m[i]);
		}
		while(true){
			found=false;
			fr(i,1,n)
				fr(j,1,n)
					if(f[i][j]>=0)
						fr(k,1,n){
							if(k==i)
								continue;
							tmp=max(abs(x[i]-x[k]),abs(y[i]-y[k]));
							arr=f[i][j]+max(tmp*100,750);
							if(arr<=m[k]+1000)
								if(f[k][j+1]==-1||f[k][j+1]>max(arr,m[k])){
									f[k][j+1]=max(arr,m[k]);
									found=true;
//									cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j]<<" "<<f[k][j+1]<<endl;
								}
						}
			if(!found)
				break;
		}
		ans=0;
		fr(i,1,n)
			fr(j,1,n)
				if(f[i][j]>=0&&ans<j)
					ans=j;					
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}

