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

int solve(vector<pair<int, pair<int, int>>> hand, vector<pair<int, pair<int, int>>> deck, int whenStop)
{
    int i, j, k;

    int turns = 1;
    int turn = 0;
    int score = 0;
    int ans = 0;
    int nxt = 0;
    while(turns > 0 && hand.size())
    {
        vector<int> scores;
        fi(hand.size()) scores.pb(hand[i].second.first);
        sort(all(scores));
        reverse(all(scores));
        int cur = 0;
        fj(min(turns, (int)scores.size())) cur += scores[j];
        ans = max(ans, score + cur);
        
        int play = -1;
        fi(hand.size())
        {
            if (hand[i].second.second > 0 && hand[i].first > 0) play = i;
        }
        if (play == -1 && turn < whenStop)
        {
            fi(hand.size())
            {
                if (hand[i].second.second > 0) play = i;
            }
        }
        if (play == -1)
        {
            fi(hand.size())
            {
                if (hand[i].first == 1 && (play == -1 || hand[play].second.second == 0 && hand[i].second.first > hand[play].second.first)) play = i;
            }
        }
        if (play == -1) break;
        
        for (i = 0; i < hand[play].first && nxt < deck.size(); ++ i)
        {
            hand.pb(deck[nxt++]);
        }
        turns += hand[play].second.second;
        score += hand[play].second.first;
        hand[play] = hand.back();
        hand.pop_back();

        -- turns; 
        ++ turn;
    }
    ans = max(ans, score);
    
    return ans;
}

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
		printf( "Case #%d: ", t );
        
        vector<pair<int, pair<int, int>>> hand, deck;
        int n = ni();
        fi(n) {
            int a = ni();
            int b = ni();
            int c = ni();
            hand.pb(mp(a, mp(b, c)));
        }
        int m = ni();
        fi(m) {
            int a = ni();
            int b = ni();
            int c = ni();
            deck.pb(mp(a, mp(b, c)));
        }

        int ans = 0;
        for(int i = 0; i < 100; ++ i) {
            ans = max(ans, solve(hand, deck, i));
        }
        
        printf("%d\n", ans);
	}

	return 0;
}
