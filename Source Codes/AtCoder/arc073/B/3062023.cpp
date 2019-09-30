#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,m,v[111]={},w[111]={};
	int mem[5][111]={},sz[5]={};
	cin>>n>>m;
	FOR(i,0,n)cin>>w[i]>>v[i];
	int t=w[0];
	FOR(i,0,4){
		priority_queue<int> pq;
		FOR(j,0,n){
			if(t+i==w[j]){
				pq.push(v[j]);
			}
		}
		int idx=0;
		while(pq.size()){
			mem[i][idx]=pq.top();
			pq.pop();
			idx++;
		}
		sz[i]=idx;
	}

	FOR(i1,1,sz[0]){
		mem[0][i1]+=mem[0][i1-1];
	}
	FOR(i2,1,sz[1]){
		mem[1][i2]+=mem[1][i2-1];
	}
	FOR(i3,1,sz[2]){
		mem[2][i3]+=mem[2][i3-1];
	}
	FOR(i4,1,sz[3]){
		mem[3][i4]+=mem[3][i4-1];
	}
	LL ans=0;
	FOR(i1,0,sz[0]+1){
		FOR(i2,0,sz[1]+1){
			FOR(i3,0,sz[2]+1){
				FOR(i4,0,sz[3]+1){
					LL wei=1LL*i1*(t+0)+1LL*i2*(t+1)+1LL*i3*(t+2)+1LL*i4*(t+3);
					if(wei>m)continue;

					ans=max(ans,0LL+mem[0][i1-1]+mem[1][i2-1]+mem[2][i3-1]+mem[3][i4-1]);
				}
			}
		}
	}
	cout<<ans;
    return 0;
}