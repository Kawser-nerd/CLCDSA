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

bool was[22][2300111];
double w[22][2300111];
string s;

double f(int n,int o){
	if (!o)return 0;
	if (was[n][o])return w[n][o];
	double r=0;
	for (int i=0;i<n;i++){
		int x = i;
		int q = n;
		while ((o&pw(x)) == 0) {
			q --;
			x ++;
			if (x==n)x=0;
		}
		r += q + f(n,o - pw(x));
	}
	r/=n;
	was[n][o] = 1;
	w[n][o] = r;
	return r;
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> s;
		int x =0;
		for (int i=0;i<s.size();i++)if (s[i] == '.')x += pw(i);
		cout.precision(10);
		cout << "Case #" << E << ": " << fixed << f((int)s.size(), x) << endl;
	}
	return 0;
}


