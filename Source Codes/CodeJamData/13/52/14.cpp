#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,x[22],y[22],p[22],aa[22],ans;

bool kk(int a,int b,int x,int y){
	if (max(a,b)<=min(x,y))return 1;
	if (max(x,y)<=min(a,b))return 1;
	return 0;
}

bool per(int x,int y,int xx,int yy,int X,int Y,int XX,int YY){
	if (x==X && y == Y)return 0;
	if (x==XX && y == YY)return 0;
	if (xx==X && yy == Y)return 0;
	if (xx==XX && yy == YY)return 0;
	long long a = yy - y;
	long long b = x - xx;
	long long c = -x * a - y * b;
	long long A = YY -Y;
	long long B = X - XX;
	long long C = -X * A - Y * B;
	if (a*B == A*b) {
		if (a*C == A*c && b*C == B*c) {
			if (kk(x,xx,X,XX) && kk(y,yy,Y,YY))return 0;
			return 1;
		}else return 0;
	}
	if ( (a*X+b*Y+c)*(a*XX+b*YY+c) <= 0 && (A*x+B*y+C)*(A*xx+B*yy+C) <= 0)return 1;
	return 0;
}


int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> n;
		for (int i=0;i<n;i++)cin >> x[i] >> y[i];
		for (int i=0;i<n;i++)p[i] = i;
		ans =0;
		do{
			p[n] = p[0];
			int bad = 0;
			for (int i=1;i<=n;i++)for (int j=1;j<i-1;j++) {
				if (per(x[p[i]],y[p[i]],x[p[i-1]],y[p[i-1]],x[p[j]],y[p[j]],x[p[j-1]],y[p[j-1]]) ){
					bad = 1;
					break;
				}
			}
			if (bad)continue;
			int ss =0;
			for (int i=1;i<=n;i++) ss += (y[p[i]] + y[p[i-1]]) * (x[p[i]] - x[p[i-1]]);
			if (abs(ss) > ans) {
				ans = abs(ss);
				for (int i=0;i<n;i++)aa[i] = p[i];
			}

		}while (next_permutation(p+1,p+n));
		cout << "Case #" << E << ":";
		for (int i=0;i<n;i++)cout << " " << aa[i];
		puts("");
	}
	return 0;
}


