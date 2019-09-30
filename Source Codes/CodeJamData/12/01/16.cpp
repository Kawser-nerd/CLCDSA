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

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORZ(i,b) FOR(i,0,(b))
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

const char* perm = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  int tt;
  cin >> tt;
  getchar();
  FOR(t,1,tt+1) {
    printf("Case #%d: ", t);
    int c;
    do {
      c = getchar();
      if (c == '\n' || c == EOF) {
        putchar('\n');
        break;
      }
      if (c == ' ') putchar(' ');
      else putchar(perm[c - 'a']);
    } while (true);
  }
  return 0;
}

