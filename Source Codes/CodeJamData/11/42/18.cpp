#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

char grid[501][501];
long long msum[501][501];
long long msumx[501][501];
long long msumy[501][501];

#define SQ(arr, i, j, sz) (arr[i+sz][j+sz]-arr[i+sz][j]-arr[i][j+sz]+arr[i][j])

void eval(){
	int R, C, D;
	scanf("%d %d %d", &R, &C, &D);
	for(int i=0; i<R; i++)
		scanf(" %s", grid[i]);
	for(int i=0; i<R; i++)
	for(int j=0; j<C; j++){
		msum[i+1][j+1]=grid[i][j]+D+msum[i+1][j]+msum[i][j+1]-msum[i][j];
		msumx[i+1][j+1]=j*(grid[i][j]+D)+msumx[i+1][j]+msumx[i][j+1]-msumx[i][j];
		msumy[i+1][j+1]=i*(grid[i][j]+D)+msumy[i+1][j]+msumy[i][j+1]-msumy[i][j];
	}
	int best=-1;
	for(int sz=min(R, C); sz>=3 && best==-1; sz--){
		for(int i=0; i+sz<=R; i++)
		for(int j=0; j+sz<=C; j++){
			long long mass=SQ(msum, i, j, sz);
			long long massx=SQ(msumx, i, j, sz);
			long long massy=SQ(msumy, i, j, sz);
			int cornerx[4]={j, j+sz-1, j, j+sz-1};
			int cornery[4]={i, i, i+sz-1, i+sz-1};
			for(int k=0; k<4; k++){
				mass-=grid[cornery[k]][cornerx[k]]+D;
				massx-=cornerx[k]*(grid[cornery[k]][cornerx[k]]+D);
				massy-=cornery[k]*(grid[cornery[k]][cornerx[k]]+D);
			}
			if(mass*(2*j+sz-1)==massx*2 && mass*(2*i+sz-1)==massy*2){
				best=sz;
				break;
			}
		}
	}
	if(best==-1)
		puts("IMPOSSIBLE");
	else
		printf("%d\n", best);
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
