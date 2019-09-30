#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const unsigned inf=0xffffffffu;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
unsigned getdelay(unsigned L,unsigned R,unsigned T0,unsigned T){
	T0%=L+R,T%=L+R;
	if(T<T0)
		T+=L+R;
	if(T<T0+L)
		return 0;
	else
		return T0+L+R-T;
}
unsigned TX[22][22],TY[22][22],T0[22][22];
unsigned dis[44][44];
bool inQ[44][44];
int main(){
	int T,tests=0;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<m;j++){
				scanf("%u%u%u",&TX[i][j],&TY[i][j],&T0[i][j]);
			}
		memset(dis,inf,sizeof(dis));
		memset(inQ,false,sizeof(inQ));
		queue<pair<int,int> > Q;
		dis[0][0]=0,inQ[0][0]=true;
		Q.push(make_pair(0,0));
		while(!Q.empty()){
			int x=Q.front().first,y=Q.front().second;
			Q.pop();
			inQ[x][y]=false;
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx<0||nx>=n*2||ny<0||ny>=m*2)
					continue;
				int ndis=dis[x][y];
				if((nx>>1)==(x>>1)&&(ny>>1)==(y>>1)){
					if(dx[i]!=0)
						ndis=ndis+getdelay(TX[x>>1][y>>1],TY[x>>1][y>>1],T0[x>>1][y>>1],ndis)+1;
					else
						ndis=ndis+getdelay(TY[x>>1][y>>1],TX[x>>1][y>>1],T0[x>>1][y>>1]+TX[x>>1][y>>1],ndis)+1;
				}else
					ndis+=2;
				if(ndis<dis[nx][ny]){
					dis[nx][ny]=ndis;
					if(!inQ[nx][ny]){
						inQ[nx][ny]=true;
						Q.push(make_pair(nx,ny));
					}
				}
			}
		}
		printf("Case #%d: %d\n",++tests,dis[n*2-1][m*2-1]);
	}
}
