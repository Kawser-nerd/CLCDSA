#include <algorithm>
#include <cstdio>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef pair<int,int> par;

int n;
par a[1000];
int color[17];

set<par> memo;

int lo;

#define W 15

int solve( int i, int top ) {
    if( i == n ) return 1;

    if( a[i].second <= lo || a[i].second > lo + W ) return solve( i+1, top );
    
    int broj = 0;
    for( int y = 1; y <= W; ++y ) broj = broj * (top+1) + color[y];
    if( memo.count( par(i,broj)) ) return 0;
    memo.insert( par(i,broj) );    
    
    int prev = color[a[i].second-lo];
    for( int c = 1; c <= top; ++c ) {
        int ok = 1;
        for( int y = a[i].second-1; y <= a[i].second+1; ++y ) 
            if( color[y-lo] && color[y-lo] == c ) 
                ok = 0;
        
        if( ok ) {
            color[a[i].second-lo] = c;
            if( solve( i+1, top ) ) return 1;
            color[a[i].second-lo] = prev;
        }
    }
    return 0;
}

int main( void ) {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; ++tt ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) 
            scanf( "%d%d", &a[i].first, &a[i].second );
        
        sort( a, a+n );
        reverse( a, a+n ); 

        int top;
        for( top = 1; top <= 3; ++top ) {
            int ok = 1;
            for( lo = 0; lo <= 30-W; ++lo ) {
                memset( color, 0, sizeof color );
                memo.clear();
                if( !solve( 0, top ) ) {
                    ok = 0;
                    break;
                }
            }
            if( ok ) break;
        }
        printf( "Case #%d: %d\n", tt, top );
    }
    return 0;
}
