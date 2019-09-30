// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER90000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int N;
		cin >> N;
		vector<double> A(N), B(N);
		for(int i =0; i < N; i++) cin >> A[i];
		sort(A.begin(),A.end());
		for(int i =0; i < N; i++) cin >> B[i];
		sort(B.begin(),B.end());
		
		int ansA =0, ansB =0;
		for(int i =0; i < N; i++) {
			// prvych i vykyda, poslednych N-i vyhra
			bool b =true;
			for(int j =0; j < i; j++)
				if(A[j] > B[N-i+j]) b =false;
			for(int j =i; j < N; j++)
				if(A[j] < B[j-i]) b =false;
			if(b) {
				ansA =N-i;
				break;}
			}
		
		for(int i =0; i < N; i++) {
			int a =0;
			for(int j =0; j < N; j++) 
				if(A[i] < B[j]) a++;
			ansB =max(ansB,N-i-a);}
		
		cout << "Case #" << t+1 << ": " << ansA << " " << ansB << "\n";}
	return 0;}
	
// look at my code
// my code is amazing