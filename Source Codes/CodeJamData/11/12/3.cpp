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

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;

map<string,int> mm[26];
        

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
		printf( "Case #%d: ", t );
        fprintf(stderr, "%d\n", t);
        
        n = ni(); m = ni();
        vector<string> d;
        vector<string> ans;
       
        fi(n) d.pb(ns());
        
        fi(m)
        {
            vector<string> q;
            
            fk(n) { q.pb(""); fj(d[k].size()) q[k].pb('_'); }
            fk(26) mm[k].clear();
        
            string alp = ns();
            fj(alp.size())
            {
                fk(n)
                {
                    int z;
                    bool ok = false;
                    fr(z, d[k].size()) if (d[k][z] == alp[j]) ok = true;
                    
                    if(ok) mm[j][q[k]] ++;
                    fr(z, d[k].size()) if (d[k][z] == alp[j]) q[k][z] = alp[j];
                }
            }
            
            fk(n) { q[k] = ""; fj(d[k].size()) q[k].pb('_'); }

            int best = -1;
            int bestId = -1;
            fk(n)
            {
                int cur = 0;
                fj(alp.size())
                {
                    int z;
                    bool ok = false;
                    fr(z, d[k].size()) if (d[k][z] == alp[j]) ok = true;
                    if (mm[j][q[k]] > 0 && !ok) { /*printf("{%s %d}", q[k].c_str(), mm[j][q[k]]);*/ ++ cur; }
                    fr(z, d[k].size()) if (d[k][z] == alp[j]) q[k][z] = alp[j];
                }
//                printf(" --- %d\n", cur);
                if (cur > best)
                {
                    best = cur;
                    bestId = k;
                }
            }
//            printf("%d %d\n", bestId, best);
            ans.pb(d[bestId]);
        }
        
        out(all(ans));
	}

	return 0;
}
