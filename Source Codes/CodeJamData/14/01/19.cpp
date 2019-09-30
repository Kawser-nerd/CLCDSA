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
#define dibs reserve
#define OVER90000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
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
		int x,y;
		cin >> x;
		int C[4][4];
		for(int i =0; i < 16; i++) cin >> C[i/4][i%4];
		cin >> y;
		int D[4][4];
		for(int i =0; i < 16; i++) cin >> D[i/4][i%4];
		int s =0, a =-1;
		for(int i =0; i < 4; i++) {
			bool b =false;
			for(int j =0; j < 4; j++) if(C[x-1][i] == D[y-1][j])
				b =true;
			if(b) {s++; a =C[x-1][i];}
			}
		cout << "Case #" << t+1 << ": ";
		if(s > 1) cout << "Bad magician!\n";
		if(s == 0) cout << "Volunteer cheated!\n";
		if(s == 1) cout << a << "\n";}
	return 0;}
	
// look at my code
// my code is amazing