#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
#define rep(i,n) for(int i=0;i<n;++i)
int main(){
	int h,w,d;
	cin >>h>>w>>d;
	vector<vector<int>> a(h,vector<int>(w));
	rep(i,h)
		rep(j,w)
			cin >>a[i][j];
	vector<pair<int,int>>r(h*w);
	rep(i,h)
		rep(j,w){
			r[a[i][j]-1]=pair<int,int>(i,j);
		}
	vector<LL> s(h*w+1);
	rep(i,h*w)
		s[i]=0;
	for (int i=0;i+d<h*w;++i){
		s[i+d]+=s[i]+abs(r[i].first-r[i+d].first)+abs(r[i].second-r[i+d].second);
	}
	int q;
	cin >>q;
	rep(kk,q){
	int l,r;
	cin >>l>>r;
	cout <<s[r-1]-s[l-1]<<endl;
	}
}