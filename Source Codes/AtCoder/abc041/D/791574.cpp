#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<math.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

vector< P > constraints( 16 * 8 );

int N, M;
bool valid[ 1 << 16 ];

/* ll calc( int flag ) */
/* { */
/*     if( flag == 0 ) return 1; */

/*     ll value = 0; */
/*     for( int i = 0; i < N; ++i ) */
/*     { */
/*         if( flag & ( 1 << i ) ) */
/*         { */
/*             int next_flag = flag & ~( 1 << i ); */
/*             if( valid[ next_flag ] ) */
/*             { */
/*                 value += calc( next_flag ); */
/*             } */
/*         } */
/*     } */
/*     return value; */
/* } */

void calcValid()
{
    for( int i = 0; i < ( 1 << N ); ++i )
    {
        valid[i] = true;
        for( int j = 0; j < M; ++j )
        {
             if( ( i & ( 1 << constraints[j].second ) ) //second?head???????
                     && !( i & ( 1 << constraints[j].first ) ) )//first?tail????
             {
                valid[i] = false;
                break;
             }
        }
    }
}

int main()
{
    // get a integer
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf( "%d %d", &x, &y );
        constraints[i].first = x - 1;
        constraints[i].second = y - 1;
    }

    calcValid();

    ll dp[1 << 16];
    dp[0] = 1;


    for (int i = 1; i < 1 << N; ++i) {
        dp[i] = 0;
        if(valid[i])
        {
            for (int j = 0; j < N; ++j) {
                if( i & ( 1 << j ) )
                {
                    dp[i] += dp[i^(1<<j)];
                }
            }
        }
    }

    /* cout << calc( ( 1 << N ) - 1 ) << endl;; */
    cout << dp[ ( 1 << N ) - 1 ] << endl;;
}