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
const int maxn=2000002;
int ca,ti,n,m,k,i,a,b,c,l;
double g[maxn],h[maxn],le[maxn],ri[maxn],x[maxn],y[maxn],ans;
double val(int len){
	int i,j;
			l=0;
			for(j=m;j>m-(k-len);j--)
				h[++l]=g[j];
			for(j=len;j>=1;j--)
				h[++l]=g[j];
	le[0]=1;
	fr(i,1,k)
		le[i]=le[i-1]*h[i];
	ri[k+1]=1;
	for(i=k;i>=1;i--)
		ri[i]=ri[i+1]*(1-h[i]);
	double tot=0;
	fr(i,0,k)
		tot+=le[i]*ri[i+1];
	return 1-tot;
}
double val2(int len){
	int w=m-(k-len)+1;
	if(len==k)
		return 1-x[len];
	if(len==0)
		return 1-y[w];		
//	cout<<len<<" "<<x[len]<<" "<<ri[w]<<" "<<y[w]<<" "<<le[len]<<endl;
	//cout<<1-(x[len]*ri[w]+y[w]*le[len]-le[len]*ri[w])<<endl;
	return 1-(x[len]*ri[w]+y[w]*le[len]-le[len]*ri[w]);
}
int main(){
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>k;
		scanf("\n");
/*		memset(le,0,sizeof(le));
		memset(ri,0,sizeof(ri));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(g,0,sizeof(g));*/
		m=0;
		fr(i,1,n){
			scanf("%d/%d %d\n",&a,&b,&c);
//			cout<<a<<" "<<b<<" "<<c<<endl;
			while(c--)
				g[++m]=double(a)/b;
		}
		sort(g+1,g+1+m);
		fr(i,1,m/2)
			swap(g[i],g[m+1-i]);
		le[0]=ri[m+1]=1;
		fr(i,1,m)
			le[i]=le[i-1]*g[i];
		for(i=m;i>=1;i--)
			ri[i]=ri[i+1]*(1-g[i]);
		fr(i,0,m)
			x[i]=le[i]*ri[i+1];
		x[0]=0;
		x[1]=1;
		fr(i,2,m)
			x[i]=x[i-1]*(1-g[i])+le[i];
//		fr(i,1,m)
	//		cout<<"X"<<x[i]<<endl;
		y[m+1]=0;
		y[m]=1;
		for(i=m-1;i>=1;i--)
			y[i]=y[i+1]*g[i]+ri[i];
//		fr(i,1,m)
	//		cout<<"Y"<<y[i]<<endl;
		ans=1;
		fr(i,0,k){
//			cout<<val2(i)<<endl;
			ans=min(ans,val2(i));
		}
		cout<<"Case #"<<ti<<": ";
		printf("%.8lf\n",ans);
	}
}

