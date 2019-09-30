#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<stdio.h>
#include<cstring>
#define fr(i,a,b) for(i=a;i<=b;++i)
#define x first
#define y second
#define point(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> point;
typedef vector<point> polygon;
const double zero=1e-8;
const double pi=acos(-1.0);
point operator+(point a,point b){
	return make_pair(a.x+b.x,a.y+b.y);
}
point operator-(point a,point b){
	return make_pair(a.x-b.x,a.y-b.y);
}
point operator*(point a,double b){
	return make_pair(a.x*b,a.y*b);
}
point operator/(point a,double b){
	return make_pair(a.x/b,a.y/b);
}
double area2(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(point a,point b){
	return sqrt(double(a.x-b.x)*(a.x-b.x)+double(a.y-b.y)*(a.y-b.y));
}
point rotate(point a,point b){
	return make_pair((b.y-a.y)+a.x,-(b.x-a.x)+a.y);
}
ostream& operator<<(ostream& os,point r){
	os<<r.x<<" "<<r.y<<" ";
	return os;
}
const int maxn=5002;
const int limit=10000;
int ca,ti,n,m,i;
point p[maxn],o;
double ans;
char u[limit*2+2][limit*2+2];
void dfs(point o,int le){
	ans=max(ans,double(o.x)*o.x+double(o.y)*o.y);
	if(le==0)
		return;
	if(abs(o.x)<=limit&&abs(o.y)<=limit){
		if(u[o.x+limit][o.y+limit]>=le)
			return;
		u[o.x+limit][o.y+limit]=le;
	}
	int i;
	fr(i,1,n)
		dfs(rotate(p[i],o),le-1);
}
int main(){
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>m;
		o=point(0,0);
		fr(i,1,n)
			cin>>p[i].x>>p[i].y;
		ans=0;
		memset(u,0,sizeof(u));
		dfs(o,m);
		cout<<"Case #"<<ti<<": ";
		printf("%.8lf\n",sqrt(ans));
	}
}

