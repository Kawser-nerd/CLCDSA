#include<map>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

#define mp make_pair

using namespace std;

const int Mxn=100005;
const int Mxm=1005;
int sum[Mxm*4][Mxm*4];
struct eeee{
	int x,y;
	char c;
}a[Mxn];
inline int find(int x,int y,int X,int Y){
	return sum[x][y]-sum[x][Y+1]-sum[X+1][y]+sum[X+1][Y+1];
}
int n,m,tm,fm;
int main(){
	cin>>n>>m;
	tm=m*2;
	fm=tm*2;
	int i,j;
	for(i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].c;
	for(i=1;i<=n;i++){
		if(a[i].c=='B') sum[a[i].x%tm][a[i].y%tm]++;
		else sum[(a[i].x+m)%tm][a[i].y%tm]++;
	}
	for(i=0;i<tm;i++) for(j=0;j<tm;j++){
		sum[i][j+tm]=sum[i][j];
		sum[i+tm][j]=sum[i][j];
		sum[i+tm][j+tm]=sum[i][j];
	}
	for(i=fm-1;i>-1;i--) for(j=fm-1;j>-1;j--) sum[i][j]=sum[i][j]+sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
	int ans=0;
	for(i=0;i<tm;i++) for(j=0;j<tm;j++) ans=max(ans,find(i,j,i+m-1,j+m-1)+find(i+m,j+m,i+tm-1,j+tm-1));
	cout<<ans<<endl;
	return 0;
}