#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>

#define gmin( a, b) (( a) < ( b) ? ( a) : ( b))
#define gmax( a, b) (( a) > ( b) ? ( a) : ( b))
#define MAX 100

using namespace std;

int C, R, c, r;
int ans;
int S[ 5][ 5];

int Dy[ 4] = { -1, 0, 0, 1}, Dx[ 4] = { 0, -1, 1, 0};

void inp( void) {

	scanf( "%d %d %d %d", &C, &R, &c, &r);

	r--; c--;

	for ( int i = 0; i < R; i++) {
		for ( int j = 0; j < C; j++) {
			scanf( "%d", &S[ i][ j]);
		}
	}
	ans = 0;
}

void prs( int d) {

	if ( S[ r][ c] <= 0) return;
	
	if ( d > ans) ans = d;

	int ch = 1;

	for ( int i = 0; i < 4; i++) {
		if ( r + Dy[ i] >= 0 && r + Dy[ i] < R && c + Dx[ i] >= 0 && c + Dx[ i] < C) {
			if ( S[ r + Dy[ i]][ c + Dx[ i]] > 0) ch = 0;
		}
	}

	if ( ch == 1) {
		ans = MAX;
		return;
	}

	int Tmp[ 5][ 5], maxx, maxy, maxv;

	for ( int i = 0; i < R; i++) {
		for ( int j = 0; j < C; j++) {
			Tmp[ i][ j] = S[ i][ j];
		}
	}

	for ( int i = 0; i < R; i++) {
		for ( int j = 0; j < C; j++) {
			if ( Tmp[ i][ j] <= 0) continue;
			if ( i == r && j == c) continue;
			maxv = 0;
			for ( int k = 0; k < 4; k++) {
				if ( i + Dy[ k] >= 0 && j + Dx[ k] >= 0 && i + Dy[ k] < R && j + Dx[ k] < C) {
					if ( Tmp[ i + Dy[ k]][ j + Dx[ k]] > maxv) {
						maxy = i + Dy[ k]; maxx = j + Dx[ k]; maxv = Tmp[ i + Dy[ k]][ j + Dx[ k]];
					}
				}
			}
			if ( maxv != 0) {
				S[ maxy][ maxx] -= Tmp[ i][ j];
			}
		}		
	}

	prs( d + 1);

	for ( int i = 0; i < 4; i++) {
		if ( r + Dy[ i] >= 0 && r + Dy[ i] < R && c + Dx[ i] >= 0 && c + Dx[ i] < C) {
			S[ r + Dy[ i]][ c + Dx[ i]] -= Tmp[ r][ c];
			prs( d + 1);
			S[ r + Dy[ i]][ c + Dx[ i]] += Tmp[ r][ c];
		}
	}

	for ( int i = 0; i < R; i++) {
		for ( int j = 0; j < C; j++) {
			S[ i][ j] = Tmp[ i][ j];
		}
	}
}

void outp( int test_num) {

	printf( "Case #%d: ", test_num);

	if ( ans == MAX) printf( "forever"); else printf( "%d day(s)", ans);

	printf( "\n");

}

int main( void) {

	int tmp;

	scanf( "%d", &tmp);

	for ( int i = 0; i < tmp; i++) {
		inp();
		prs( 0);
		outp( i + 1);
	}

	return 0;
}
