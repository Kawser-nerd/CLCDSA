#include<iostream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=22;
const __int64 limit=__int64(1)<<60;
int s[maxn][maxn],w[maxn][maxn],t[maxn][maxn],i,j,n,m,ti,ca,k;
__int64 f[maxn][maxn][4];
bool found=false;
void update(int a,int b,int c,__int64 tmp){
	if(a<1||a>n||b<1||b>m||f[a][b][c]<=tmp)
		return;
	f[a][b][c]=tmp;
	found=true;
}
__int64 cal(__int64 now,__int64 s,__int64 w,__int64 t){
	__int64 interval=((now-t)%(s+w)+s+w)%(s+w);
	if(interval<s)
		return now+1;
	else
		return now+1+(s+w)-interval;
}
int main(){
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>m;
		fr(i,1,n)
			fr(j,1,m)
				cin>>s[i][j]>>w[i][j]>>t[i][j];
		fr(i,1,n)
			fr(j,1,m)
				fr(k,0,3)
					f[i][j][k]=limit;
		f[n][1][0]=0;
		do{
			found=false;
			fr(i,1,n)
				fr(j,1,m){
					update(i,j,3,cal(f[i][j][0],s[i][j],w[i][j],t[i][j]));
					update(i,j,1,cal(f[i][j][0],w[i][j],s[i][j],t[i][j]+s[i][j]));
					update(i,j-1,1,f[i][j][0]+2);
					update(i+1,j,3,f[i][j][0]+2);
					update(i,j,2,cal(f[i][j][1],s[i][j],w[i][j],t[i][j]));
					update(i,j,0,cal(f[i][j][1],w[i][j],s[i][j],t[i][j]+s[i][j]));
					update(i,j+1,0,f[i][j][1]+2);
					update(i+1,j,2,f[i][j][1]+2);
					update(i,j,1,cal(f[i][j][2],s[i][j],w[i][j],t[i][j]));
					update(i,j,3,cal(f[i][j][2],w[i][j],s[i][j],t[i][j]+s[i][j]));
					update(i-1,j,1,f[i][j][2]+2);
					update(i,j+1,3,f[i][j][2]+2);
					update(i,j,0,cal(f[i][j][3],s[i][j],w[i][j],t[i][j]));
					update(i,j,2,cal(f[i][j][3],w[i][j],s[i][j],t[i][j]+s[i][j]));
					update(i-1,j,0,f[i][j][3]+2);
					update(i,j-1,2,f[i][j][3]+2);
				}
		}while(found);
		printf("Case #%d: %I64d\n",ti,f[1][m][2]);
	}
}