#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
#include <deque>
#include <cstring>
#include <sys/time.h>
#include <sys/time.h>
using namespace std;
long long INF = 2e9;
int idx[220][5010];
 
int st,en;
 
void solve(long long N, long long M, vector<long long> A, vector<vector<long long>> B){
	
	memset(idx,-1,sizeof(idx));
	long long ans = 0;
	for(int i = 0 ; i < N ; i++){
		long long sub = 0;
		for(int j = 0 ; j < M ; j++){	
			sub += B[i][j];
		}
		ans = max(sub,ans);
	}
	for(int i = 1 ; i < A.size() ; i++)
		A[i] = A[i-1] + A[i];
	//cout << "><" << endl;
	for(int i = 0 ; i < M ; i++){
		deque<long long> X;
		deque<long long> Y;
		
		X.push_front(INF);
		Y.push_front(N);
		
		for(int j = N - 1 ; j >= 0 ; j--){
			int l = 0, r = X.size() - 1;
			while( l != r ){
				int m = (l+r) / 2;
				if( X[m] > B[j][i] ){
					r = m;
				}else{
					l = m + 1;
				}
			}
			idx[i][j] = Y[r];
			//cout << "idx[" << i << "][" << j << "]" << "=" << Y[r] << "(" << B[j][i] << ")" << endl;
			assert(j < Y[r]);
			
			while( X.front() <= B[j][i] ){
				X.pop_front();
				Y.pop_front();
			}
			X.push_front(B[j][i]);
			Y.push_front(j);
		}
	}
	
	for(int i = N-1 ; i >= 0 ; i--){
		en = clock();
		//cout << en << endl;
		if( 1.0 * (en - st) / CLOCKS_PER_SEC > 1.9  ) break;
		//cout << 1.0 * (en - st) / CLOCKS_PER_SEC  << endl;
		long long mx[200]={};
		int id[200]={};
		long long dist = 0;
		
		
		for(int j = i ; j < N ; ){
			
			for(int k = 0 ; k < M ; k++){	
				mx[k] = max(mx[k],B[j][k]);
			}
			long long sub = 0;
			for(int k = 0 ; k < M ; k++){	
				sub += mx[k];
			}
			ans = max(sub-dist,ans);
			//cout << sub << "|" <<  dist << "[" << i << "," << j << "]" << endl;
			int nx = N;
			
			for(int k = 0 ; k < M ; k++)
				id[k] = max(id[k], idx[k][j]);
			
			for(int k = 0 ; k < M ; k++)
				nx = min(id[k],nx);
			dist += A[nx-1] - (j?A[j-1]:0);
			//cout << j << "->" << nx << " " << N << endl;
			j = nx;
			//cout << i << " " << nx << endl;
			
			
		}
	}
	cout << ans << endl;
}
 
int main(){
	st = clock();
 
	long long N;
	long long M;
	scanf("%lld",&N);
	vector<long long> A((N-1)-1+1);
	scanf("%lld",&M);
	vector<vector<long long>> B(N-1+1,vector<long long>(M-1+1));
	for(int i = 0 ; i <= (N-1)-1 ; i++){
		scanf("%lld",&A[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		for(int j = 0 ; j <= M-1 ; j++){
			scanf("%lld",&B[i][j]);
		}
	}
	solve(N, M, A, B);
	return 0;
 
/*
	long long N;
	long long M;
	//scanf("%lld",&N);
	N = 5000;
	M = 200;
	vector<long long> A((N-1)-1+1);
	//scanf("%lld",&M);
	vector<vector<long long>> B(N-1+1,vector<long long>(M-1+1));
	for(int i = 0 ; i <= (N-1)-1 ; i++){
		//scanf("%lld",&A[i]);
		A[i] = rand() % 1000;
	}
	for(int i = 0 ; i <= N-1 ; i++){
		for(int j = 0 ; j <= M-1 ; j++){
			B[i][j] = rand() % 1000000;
		}
	}
	solve(N, M, A, B);
	return 0;
*/
}