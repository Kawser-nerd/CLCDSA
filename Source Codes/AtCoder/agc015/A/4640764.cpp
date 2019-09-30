#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	lint a,b,n,ma,mi;
	cin>>n>>a>>b;
	if(a>b){
		cout<<0<<endl;return 0;
	}
	if(n==1){
		if(a==b) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	ma=a+(n-1)*b;mi=b+(n-1)*a;
	cout<<(ma-mi+1)<<endl;
}