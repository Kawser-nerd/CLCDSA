#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int inf=100000000;
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
 
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	ll g=gcd(a,b);
	return a/g*b;
}
 
ll digitsum(ll a){
	ll x=0;
	while(a>0){
		x+=a%10;
		a/=10;
	}
	return x;
}
int r,c;
char s[55][55];
int d[55][55];
int bfs(){
	int sx=0,sy=0,gx=r-1,gy=c-1;
	int dx[4]={1,0,-1,0} ,dy[4]={0,1,0,-1};
	queue<p> que;
	rep(i,0,r){
		rep(j,0,c){
			d[i][j]=inf;
		}
	}
	que.push(p(sx,sy));
	d[sx][sy]=0;
	while(que.size()){
		p pf=que.front();
		que.pop();
		
		if(pf.first==r-1&&pf.second==c-1) break;
		rep(i,0,4){
			int nx=pf.first+dx[i],ny=pf.second+dy[i];
			if(nx>=0&&nx<r&&ny>=0&&ny<c&&s[nx][ny]!='#'&&d[nx][ny]==inf){
				que.push(p(nx,ny));
				d[nx][ny]=d[pf.first][pf.second]+1;
			}
		}
	}
	return d[r-1][c-1];
}
int main(){
	int wsum=0;
	cin>>r>>c;
	rep(i,0,r){
		rep(j,0,c){
			cin>>s[i][j];
			if(s[i][j]=='.')wsum++;
		}
	}
	int reach=bfs();
	if(reach==inf){
		cout<<-1<<endl;
	}
	else{
		cout<<wsum-reach-1<<endl;
	}
}