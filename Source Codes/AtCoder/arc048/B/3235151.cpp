#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
int sum[100001];
int C[100001][3];
int R[100000];
int H[100000];
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		R[i] = rei();
		H[i] = rei()-1;
		sum[R[i]]++;
		C[R[i]][H[i]]++;
	}
	for(int i=0;i<100000;i++){
		sum[i+1] += sum[i];
	}
	for(int i=0;i<N;i++){
		int w = sum[R[i]-1] + C[R[i]][(H[i]+1)%3];
		int m = C[R[i]][H[i]];
		int l = N-w-m;
		m--;
		cout << w << " " << l << " " << m << endl;
	}
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}