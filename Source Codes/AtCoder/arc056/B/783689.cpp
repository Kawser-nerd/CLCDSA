#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<math.h>
using namespace std;

typedef pair<int,int> P;
typedef tuple<int,int,int> TP;

#define INF ( 1 << 29 )


vector< int > links[ 200001 ];
int dists[ 200001 ];

void dijkstra( int S )
{
    priority_queue< P > pq;

    pq.push( make_pair( S, S ) );
    dists[S] = S;

    while( !pq.empty() )
    {
        int id = pq.top().second;
        pq.pop();

        for( int i = 0; i < links[id].size(); ++i )
        {
            int y = links[id][i];
            int d = min( y, dists[id] );
            if( d > dists[y] )
            {
                dists[y] = d;
                pq.push( make_pair( d, y ) );
            }
        }
    }
}

int main()
{
    int N, M, S;
    cin >> N >> M >> S;
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf( "%d %d", &u, &v );
        links[u].push_back( v );
        links[v].push_back( u );
    }

    for (int i = 1; i <= N; ++i) {
        dists[ i ] = -INF;
    }

    dijkstra( S );

    for (int i = 1; i <= N; ++i) {
        if( dists[ i ] >= i ) { printf( "%d\n", i ); }
    }
}