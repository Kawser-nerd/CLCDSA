#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b)-1);i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int x, y, r;

bool dc(int X, int Y){
	if((X-x)*(X-x) + (Y-y)*(Y-y) > r*r) return true;
	return false;
}

int main(void){
	int a, b, c, d;
	cin >> x >> y >> r >> a >> b >> c >> d;
	
	if(!(a<=x-r&&x+r<=c&&b<=y-r&&y+r<=d)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
	if(dc(a,b)||dc(a,d)||dc(c,b)||dc(c,d)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}