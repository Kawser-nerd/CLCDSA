#include<iostream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=42;
double c[maxn][maxn],f[maxn];
int i,j,n,ca,ti,type;
int main(){
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	memset(c,0,sizeof(c));
	fr(i,0,maxn-1)
		fr(j,0,i)
			if(i==j||j==0)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j]+c[i-1][j-1];
	cin>>ca;
	fr(ti,1,ca){
		cin>>type>>n;
		memset(f,0,sizeof(f));
		fr(i,1,type){
			fr(j,1,i){
				if(j>n)
					break;
				f[i]+=c[i][j]/c[type][n]*c[type-i][n-j]*(f[i-j]+1);
			}
			double k=c[type-i][n]/c[type][n];
			f[i]+=k;
			f[i]/=(1-k);
		}
		printf("Case #%d: %.7lf\n",ti,f[type]);
	}
}