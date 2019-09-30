#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int R, C;
int boxes;

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 }; 

typedef vector<string> vs;
typedef pair<vs, int> qitem;

void enqueue( queue<qitem> &Q, set<vs> &seen, vs &a, int d ) {
    if( seen.count( a ) ) return;
    seen.insert( a );
    Q.push( qitem(a,d) );
}

inline int empty( vs &a, int r, int c ) {
    if( r < 0 || r >= R || c < 0 || c >= C ) return 0;
    return a[r][c] == '.' || a[r][c] == 'x';
}

inline int box( vs &a, int r, int c ) {
    if( r < 0 || r >= R || c < 0 || c >= C ) return 0;
    return a[r][c] == 'o' || a[r][c] == 'w';
}

inline void get_box( vs &a, int r, int c ) {
    if( a[r][c] == 'o' ) a[r][c] = '.';
    else if( a[r][c] = 'w' ) a[r][c] = 'x';
}

inline void put_box( vs &a, int r, int c ) {
    if( a[r][c] == '.' ) a[r][c] = 'o';
    else if( a[r][c] = 'x' ) a[r][c] = 'w';
}
char bio[16][16];

int dfs( vs &a, int r, int c ) {
    if( !box( a, r, c ) ) return 0;
    if( bio[r][c] ) return 0;
    bio[r][c] = 1;
    int ret = 1;
    for( int d = 0; d < 4; ++d ) 
        ret += dfs( a, r+dr[d], c+dc[d] );
    return ret;
}

int dangerous( vs &a ) {
    memset( bio, 0, sizeof bio );
    for( int r = 0; r < R; ++r ) 
        for( int c = 0; c < C; ++c ) 
            if( box( a, r, c ) ) 
                return dfs( a, r, c ) < boxes;
    return -1;
}

int final( vs &a ) {
    for( int r = 0; r < R; ++r ) 
        for( int c = 0; c < C; ++c ) 
            if( a[r][c] == 'o' ) return 0;
    return 1;
}

int main( void ) {
    int T;
    cin >> T;
    for( int tt = 1; tt <= T; ++tt ) {
        cin >> R >> C;
        vs a(R);
        
        boxes = 0;
        for( int r = 0; r < R; ++r ) {
            cin >> a[r];
            for( int c = 0; c < C; ++c ) boxes += box( a, r, c );
        }

        queue<qitem> Q;
        set<vs> seen;
        enqueue( Q, seen, a, 0 );

        while( !Q.empty() ) {
            a = Q.front().first;
            int dist = Q.front().second;

            if( final(a) ) {
                printf( "Case #%d: %d\n", tt, dist );
                break;
            }
            Q.pop();

            if( dangerous( a ) ) {
                for( int r = 0; r < R; ++r ) 
                    for( int c = 0; c < C; ++c ) {
                        if( !box( a, r, c ) ) continue;
                        for( int d = 0; d < 4; ++d ) {
                            if( !empty( a, r-dr[d], c-dc[d] ) || !empty( a, r+dr[d], c+dc[d] ) ) continue;
                            
                            vs b = a;
                            get_box( b, r, c );
                            put_box( b, r+dr[d], c+dc[d] );
                            if( !dangerous(b) ) enqueue( Q, seen, b, dist+1 );
                        }
                    }
            } else {
                for( int r = 0; r < R; ++r ) 
                    for( int c = 0; c < C; ++c ) {
                        if( !box( a, r, c ) ) continue;
                        for( int d = 0; d < 4; ++d ) {
                            if( !empty( a, r-dr[d], c-dc[d] ) || !empty( a, r+dr[d], c+dc[d] ) ) continue;
                            
                            vs b = a;
                            get_box( b, r, c );
                            put_box( b, r+dr[d], c+dc[d] );
                            enqueue( Q, seen, b, dist+1 );
                        }
                    }
            }
        }
        if( Q.empty() ) {
            printf( "Case #%d: -1\n", tt );    
        }
        fprintf( stderr, "Case #%d\n", tt );
    }
    return 0;
}
