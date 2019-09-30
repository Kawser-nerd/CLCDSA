#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( ", " ); first = false; cout << * i; } printf( "" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;
char moo[300][300];
bool hru[300][300];
int lastV[300];
int num[300];
int curV = 0;
vector<char> vv;

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
        _(moo, 0); _(hru, 0);
		printf( "Case #%d: ", t );
        int c = ni();
        fi(c) { string s = ns(); moo[s[0]][s[1]] = s[2]; moo[s[1]][s[0]] = s[2]; }
        
        int q = ni();
        fi(q) { string s = ns(); hru[s[0]][s[1]] = 1; hru[s[1]][s[0]] = 1;}
        
        n = ni();
        string v = ns();
        vv.clear();
        curV = 1;
        _(lastV, 0);
        
        fi(n) {
            char c = v[i];
            while (vv.size() && moo[vv.back()][c]) {
                -- num[vv.back()];
                c = moo[vv.back()][c];
                vv.pop_back();
            }
            for (int i = 0; i < 26; ++ i) {
                if (hru[i+'A'][c] && lastV[i + 'A'] == curV && num[i + 'A']) {
                    vv.clear();
                    ++ curV;
                    goto e;
                }
            }
            if (lastV[c] < curV) { lastV[c] = curV; num[c] = 0; }
            ++ num[c];
            vv.pb(c);
            e:;
        }
        printf("[");
        out(all(vv));
        printf("]\n");
        
	}

	return 0;
}
