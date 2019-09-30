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
		int R,C,M;
		cin >> R >> C >> M;
		M =R*C-M;
		if(M == 1) {
			cout << "Case #" << t+1 << ":\n";
			for(int i =0; i < R; i++) for(int j =0; j < C; j++) 
				cout << ((i+j == 0)?"c":"*") << ((j == C-1)?"\n":"");
			continue;}
		string ch ="*.c";
		if(R == 1 || C == 1) {
			cout << "Case #" << t+1 << ":\n";
			vector< vector<int> > A(R,vector<int>(C,0));
			A[0][0] =2;
			for(int i =1; i < M; i++) {
				if(R == 1) A[0][i] =1;
				else A[i][0] =1;}
			for(int i =0; i < R; i++) for(int j =0; j < C; j++)
				cout << ch[A[i][j]] << ((j == C-1)?"\n":"");
			continue;}

		int ansX =-1, ansY =-1;
		for(int x =2; x <= R; x++) for(int y =2; y <= C; y++)
			if(x*y >= M && 2*(x+y-2) <= M) 
				ansX =x, ansY =y;
		
		cout << "Case #" << t+1 << ":\n";
		if(ansX == -1) {cout << "Impossible\n"; continue;}
		vector< vector<int> > A(R,vector<int>(C,0));
		for(int i =0; i < ansX; i++) A[i][0] =A[i][1] =1;
		for(int i =0; i < ansY; i++) A[0][i] =A[1][i] =1;
		M -=2*ansX+2*ansY-4;
		for(int i =2; i < ansX; i++) for(int j =2; j < ansY; j++) if(M > 0) {
			A[i][j] =1;
			M--;}
		A[0][0] =2;
		for(int i =0; i < R; i++) for(int j =0; j < C; j++)
			cout << ch[A[i][j]] << ((j == C-1)?"\n":"");
		}
	return 0;}
	
// look at my code
// my code is amazing