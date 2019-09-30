#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
int n,k;
vector<vector<int> >  e(2005);
vector<int> A,B;
int d [2005][2005];
void dfs(int cur,int from,int root,int curDist){
	d[root][cur] = curDist;
	for(int i = 0;i<e[cur].size();i++){
		int t = e[cur][i];
		if(t !=from)dfs(t,cur,root,curDist+1);
	}
}

int main(){
	cin >>  n >> k ;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin >>  a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
		A.push_back(a);
		B.push_back(b);
	}
	for(int i = 0;i<n;i++){
		dfs(i,-1,i,0);
	}
	int ans  = 0;
	for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int j = 0;j<n;j++){
			if(2*d[i][j] <=k)cnt++;
		}
		ans = max(ans,cnt);
	}
	for(int i =0;i<n-1;i++){
		int a = A[i];
		int b = B[i];
		int cnt = 0;
		for(int j =0;j<n;j++){
			if(2*min(d[j][a],d[j][b])+1<=k){
				cnt++;
			}
		}
		ans = max(ans,cnt);
	}
	cout << n- ans <<endl;
}