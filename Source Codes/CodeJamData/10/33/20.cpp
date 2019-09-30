#include<iostream>
#include<cmath>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=514;
int ans[maxn],g[maxn][maxn],f[maxn][maxn],i,j,k,ti,ca,n,m,value,a,b,tot=0;
char s[maxn];
void cal(int a,int b){
	int newv;
	if(g[a][b]==-1)
		newv=0;
	else{
		int k=min(min(f[a+1][b],f[a][b+1]),f[a+1][b+1]);
		if(k==0||g[a][b]==g[a+1][b]||g[a][b]==g[a][b+1]||g[a][b]!=g[a+1][b+1])
			newv=1;
		else
			newv=k+1;
	}
	if(newv!=f[a][b]){
		f[a][b]=newv;
		if(a>1)
			cal(a-1,b);
		if(b>1)
			cal(a,b-1);
		if(a>1&&b>1)
			cal(a-1,b-1);
	}
}
int main(){
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		memset(g,255,sizeof(g));
		memset(f,0,sizeof(f));
		cin>>n>>m;
		fr(i,1,n){
			cin>>s;
			k=0;
			fr(j,0,m/4-1){
				value=(s[j]<='9'?s[j]-'0':s[j]-'A'+10);
				g[i][++k]=(value>>3)&1;
				g[i][++k]=(value>>2)&1;
				g[i][++k]=(value>>1)&1;
				g[i][++k]=value&1;
			}
		}
		cal(n,m);
		memset(ans,0,sizeof(ans));
		for(k=min(n,m);k>=1;k--)
			fr(i,1,n)
				fr(j,1,m)
					if(f[i][j]==k){
						ans[k]++;
						fr(a,i,i+k-1)
							fr(b,j,j+k-1)
								g[a][b]=-1;
						cal(i+k-1,j+k-1);
					}	
		tot=0;
		fr(i,1,n)
			if(ans[i])
				++tot;
		cout<<"Case #"<<ti<<": "<<tot<<endl;
		for(i=n;i>=1;i--)
			if(ans[i])
				cout<<i<<" "<<ans[i]<<endl;
	}
}