#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#define rep( i, a, n ) for( int i = a; i < n; i++ )
#define per( i, a, n ) for( int i = n - 1; i >= a; i-- )
#define mem( f, x ) memset( f, x, sizeof( f ) )
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define MOD 1000000007
#define INF 0x3f3f3f3f

using namespace std;
const int N = 4e5 + 5;
const int M = 4e5+5;
const int MAX = 5;
const ll inv = 500000004;
const double g = 9.80;
const double PI = acos( -1.0 );
int m, n, t, cnt, ct;
int io[N][2], ft[N];
bool vis[N];
char s[N];

struct eg{
    int to, next;
    eg( ){ to = next = 0; }
    eg( int tt, int nn ){ to = tt, next = nn; }
}e[M];

void add( int x, int y ){
    e[++cnt] = eg( y, ft[x] );
    ft[x] = cnt;
}

bool topu( ){
    queue<int> q;
    while( !q.empty() ) q.pop();
    rep( i, 1, n + 1 ){
        if( !io[i][0] || !io[i][1] ){
            q.push( i );
            vis[i] = 1;
        }
    }
    int sum = 0;
    while( !q.empty() ){
        sum++;
        int tmp = q.front();
        q.pop();
        for( int i = ft[tmp]; i; i = e[i].next ){
            int to = e[i].to;
            if( !vis[to] ){
                if( --io[to][s[tmp] == 'B'] == 0 ){
                    vis[to] = 1;
                    q.push( to );
                }
            }
        }
    }
    return sum == n;
}

int main( ){
    while( scanf( "%d %d", &n, &m ) != EOF ){
        mem( ft, 0 );
        mem( vis, 0 );
        mem( io, 0 );
        scanf( "%s", s + 1 );
        rep( i, 1, m + 1 ){
            int x, y;
            scanf( "%d %d", &x, &y );
            add( x, y );
            add( y, x );
            io[x][s[y] == 'B']++;
            io[y][s[x] == 'B']++;
        }
        if( topu() ) puts( "No" );
        else puts( "Yes" );
    }
    return 0;
}