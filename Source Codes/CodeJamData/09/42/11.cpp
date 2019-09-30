#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int R, C, F;
char a[50][51];
int down[50][50];

short memo[50][50][50][50];

inline int walkable( int r, int c, int c_L, int c_R ) {
    if( c < 0 || c >= C ) return 0;
    return (a[r][c] == '.' || c >= c_L && c <= c_R) && a[r+1][c] == '#';
}

inline int fallable( int r, int c, int c_L, int c_R ) {
    if( c < 0 || c >= C ) return 0;
    return (a[r][c] == '.' || c >= c_L && c <= c_R) && down[r][c] > 0 && down[r][c] <= F;
}

short rec( int r, int c, int c_L, int c_R ) {
    if( r == R-1 ) return 0;

    short &ret = memo[r][c][c_L][c_R];
    if( ret >= 0 ) return ret;
    ret = 0x7FFF;

    int L = c, R = c;
    while( walkable( r, L-1, c_L, c_R ) ) --L;
    while( walkable( r, R+1, c_L, c_R ) ) ++R;

    if( fallable( r, L-1, c_L, c_R ) )
        ret = min( (int)ret, 0 + rec(r+down[r][L-1], L-1, L-1, L-1) );

    if( fallable( r, R+1, c_L, c_R ) )
        ret = min( (int)ret, 0 + rec(r+down[r][R+1], R+1, R+1, R+1) );

    if( L != R )
        for( int cc = L; cc <= R; ++cc )
            if( down[r+1][cc] < F )
                ret = min( (int)ret, 1 + rec(r+1+down[r+1][cc], cc, cc, cc) );

    for( int c1 = L+1; c1 <= R; ++c1 ) if( down[r+1][c1] == 0 )
        for( int c2 = c1; c2 <= R; ++c2 )
            ret = min( (int)ret, c2-c1+1 + rec(r+1, c1, c1, c2) );

    for( int c2 = L; c2 < R; ++c2 ) if( down[r+1][c2] == 0 )
        for( int c1 = L; c1 <= c2; ++c1 )
            ret = min( (int)ret, c2-c1+1 + rec(r+1, c2, c1, c2) );

    return ret;
}

int main( void ) {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; ++tt ) {
        scanf( "%d%d%d", &R, &C, &F );
        for( int r = 0; r < R; ++r ) scanf( "%s", a[r] );

        for( int c = 0; c < C; ++c ) down[R-1][c] = 0;
        for( int r = R-2; r >= 0; --r )
            for( int c = 0; c < C; ++c )
                down[r][c] = a[r+1][c] == '#' ? 0 : 1+down[r+1][c];

        memset( memo, -1, sizeof memo );

        int ret = rec( 0, 0, 0, 0 );

        if( ret == 0x7FFF )
            printf( "Case #%d: No\n", tt );
        else
            printf( "Case #%d: Yes %d\n", tt, ret );
    }
    return 0;
}
