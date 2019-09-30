#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
void win(){
	if(1) cout << "RICHARD" << endl;
	if(0) cout << "Y ";
}
void lose(){
	if(1)cout << "GABRIEL" << endl;
	if(0) cout << "N ";
}
main() {
	FILE *fin = freopen("D-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("D-large.out", "w", stdout);
	int T;
	cin >> T;
	//for(int x1 = 1; x1 <= 7; x1++){
	//for(int r1 = 1; r1 <= 10; r1++){
	//for(int c1 = 1; c1 <= 10; c1++){
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int x, r, c;
		cin >> x >> r >> c;
		//x = x1;
		//r = r1;
		//c = c1;
		if(c < r) swap(r,c);
		if((r*c) % x != 0){
			win(); continue;
		}
		if(x == 1 || x == 2){
			lose(); continue;
		}
		if(x > c){
			win(); continue;
		}
		if((x >= (r*2+1))){
			win(); continue;
		}
		/*if(x == 4 && (r == 2) && (c == 4)){
			win(); continue;
		}*/
		if(x == 3){
			lose(); continue;
		}
		if(x == 4){
			if(r == 2){
				win(); continue;
			}
			lose(); continue;
		}
		if(x >= 7){
			win(); continue;
		}
		if(x == 5){
			if(r == 3 && c == 5){
				win(); continue; // W pentomino
			}
			lose(); continue;
		}
		if(x == 6){
			if(r == 3){
				win(); continue;
			}
			lose(); continue;
		}

	//}
	//cout << endl;
	//}
	//cout << endl;
	}
	exit(0);
}