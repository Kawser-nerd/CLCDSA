#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
#define ll long long 
#define fr(b) for (int i = 0; i < b; ++i)
int abs(int x){
	if (x < 0) return -x;
	return x;
}
int main(){
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	int dx = abs(tx-sx);
	int dy = abs(ty-sy);
	if (sx <= tx && sy <= ty){
		fr(dx) printf("R");
		fr(dy) printf("U");
		fr(dx) printf("L");
		fr(dy) printf("D");
		printf("D");
		fr(dx+1) printf("R");
		fr(dy+1) printf("U");
		printf("LU");
		fr(dx+1) printf("L");
		fr(dy+1) printf("D");
		printf("R\n");
	}
	if (sx <= tx && sy >= ty){
		fr(dx) printf("R");
		fr(dy) printf("D");
		fr(dx) printf("L");
		fr(dy) printf("U");
		printf("U");
		fr(dx+1) printf("R");
		fr(dy+1) printf("D");
		printf("LD");
		fr(dx+1) printf("L");
		fr(dy+1) printf("U");
		printf("R\n");
	}
	if (sx >= tx && sy <= ty){
		fr(dx) printf("L");
		fr(dy) printf("U");
		fr(dx) printf("R");
		fr(dy) printf("D");
		printf("D");
		fr(dx+1) printf("L");
		fr(dy+1) printf("U");
		printf("RU");
		fr(dx+1) printf("R");
		fr(dy+1) printf("D");
		printf("L\n");
	}
	if (sx >= tx && sy >= ty){
		fr(dx) printf("L");
		fr(dy) printf("D");
		fr(dx) printf("R");
		fr(dy) printf("U");
		printf("U");
		fr(dx+1) printf("L");
		fr(dy+1) printf("D");
		printf("RD");
		fr(dx+1) printf("R");
		fr(dy+1) printf("U");
		printf("L\n");
	}
	return 0;
}