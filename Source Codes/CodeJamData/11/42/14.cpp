#include <iostream>
using namespace std;
typedef long long ll;
int R,C,temp;
ll w[3][500][500];
ll sum[3][501][501];
ll Sum(int d,int i0,int i1,int j0,int j1){
	ll ans=sum[d][i1][j1]+sum[d][i0][j0]-sum[d][i1][j0]-sum[d][i0][j1];
	return ans-w[d][i1-1][j1-1]-w[d][i0][j1-1]-w[d][i1-1][j0]-w[d][i0][j0];
}
bool is_good(int i0,int i1,int j0,int j1){
	ll w0=Sum(0,i0,i1,j0,j1);
	ll w1=Sum(1,i0,i1,j0,j1);
	ll w2=Sum(2,i0,i1,j0,j1);
	return (i0+i1)*w0==w1 && (j0+j1)*w0==w2;
}
int main(){
	int tnum,tcou=0;cin>>tnum;
	while (tnum--){
		cin>>R>>C>>temp;
		for (int i=0;i<R;++i)
			for (int j=0;j<C;++j){
				char c;
				cin>>c;
				w[0][i][j]=c-'0';
			}
		memset(sum,0,sizeof sum);
		for (int i=1;i<=R;++i)
			for (int j=1;j<=C;++j){
				ll W=w[0][i-1][j-1];
				w[1][i-1][j-1]=W*(2*i-1);
				w[2][i-1][j-1]=W*(2*j-1);
				for (int d=0;d<3;++d){
					sum[d][i][j]=sum[d][i-1][j]+sum[d][i][j-1]-sum[d][i-1][j-1]+w[d][i-1][j-1];
				}
			}
		int ans=-1;
		for (int k=3;k<=R && k<=C;++k)
			for (int i=0;i+k<=R;++i)
				for (int j=0;j+k<=C;++j)
					if (is_good(i,i+k,j,j+k))
						ans=k;
		cout<<"Case #"<<++tcou<<": ";
		if (ans==-1)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
