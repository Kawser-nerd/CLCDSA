#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;

int N,K;
/* ll win[2001]; */
int a[2010];
int dp[2010][2010];
int s[2010];

#define INF ( 1 << 30 )
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int main()
{
    // get a integer
    ll N, K;
    cin >> N >> K;

    ll total_match = 0;
    s[0] = 0;
    for( int i = 0; i < N; ++i )
    {
        scanf( "%d", &a[i] );
        total_match += a[i];
        s[i+1] += s[i] + a[i];
    }

    if( total_match == K )
    {
        cout << 1 << endl;
        return 0;
    }

    for( int i = 0; i < N + 1; ++i )
    {
        for( int j = 0; j < N + 1; ++j )
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

#if 0
    int i,j;

    cin >> N >> K;
    REP(i,N) cin >> a[i];

    int sum = 0;
    REP(i,N) sum += a[i];
    if(sum == K){
        cout << 1 << endl;
        return 0;
    }

    REP(i,N) s[i+1] = s[i] + a[i];

    REP(i,N+1) REP(j,N+1) dp[i][j] = INF;
    dp[0][0] = 0;

    REP(i,N) REP(j,i+1) if(dp[i][j] != INF){
		dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
		
		if(i == 0){
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);
		} else {
			int tmp = (ll)dp[i][j] * s[i+1] / s[i] + 1;
			if(tmp <= dp[i][j] + a[i]) dp[i+1][j+1] = min(dp[i+1][j+1], tmp);
		}
	}
#endif

    for(int i = 0; i < N; ++i )
    {
        /* for( int j = (i+1); j >= 0; --j ) */
        for(int j = 0; j < i + 1; ++j )
        {
            if(dp[i][j] != INF)
            {
                dp[i+1][j] = min( dp[i+1][j], dp[i][j] );

                if( i == 0 )
                {
                    dp[i+1][j+1] = min( dp[i+1][j+1], dp[i][j] + 1 );
                }
                else
                {
                    int tmp = (ll)dp[i][j] * s[i+1] / s[i] + 1;
                    if( tmp <= ( dp[i][j] + a[i] ) )
                    {
                        dp[i+1][j+1] = min( dp[i+1][j+1], tmp );
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N+1; ++i )
    {
        /* cout << i << endl; */
        if( dp[N][i] <= K )
        {
            ans = i;
        }
    }
    cout << ans << endl;

#if 0
    win[0] = 0;
    ll total = 0;
    for( int i = 0; i < N; ++i )
    {
        /* cout << i << "-------" << endl; */
        for( int j = (i+1); j > 0; --j )//???????
        {
            if( total == 0 )
            {
                win[j] = 1; 
            }
            else
            {
                ll new_win = (ll)( ( ( total + a[i] ) * win[j-1] ) / ( double )(total) ) + 1;
                /* cout << j << "," << new_win << "," << win[j-1] << "," << total << endl; */
                if( new_win <= ( a[i] + win[j-1] ) )
                {
                    /* cout << k << "," << win[j-1] << "," << total << endl; */
                    win[j] = min( win[j], new_win );
                }
            }
            /* cout << j << "," << win[j] << endl; */
        }
        total += a[i];
    }

    for( int i = N; i > 0; --i )
    {
        /* cout << win[i] << endl; */
        if( win[i] <= K )
        {
            cout << i << endl;
            break;
        }
    }
#endif
}