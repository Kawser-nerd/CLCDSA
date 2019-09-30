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
#define e 2.71828
using namespace std;
const int N = 105;
const int M = 1e6+5;
const int MAX = 5;
const ll inv = 500000004;
const double g = 9.80;
const double PI = acos( -1.0 );
int n;
ll m;
ll a[N], sum[N];

int main(){
    while( scanf( "%d %lld", &n, &m ) != EOF ){
        mem( sum, 0 );
        rep( i, 1, n + 1 ) scanf( "%lld", a + i );
        sort( a + 1, a + n + 1 );
        int ans = 0;
        rep( i, 1, n ){
            sum[i] += sum[i-1] + a[i];
            if( m >= sum[i] ) ans++;
        }
        sum[n] = sum[n-1] + a[n];
        if( m == sum[n] ) ans++;
        printf( "%d\n", ans );
    }
    return 0;
}