#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
////////////MAXFLOW from shygypsy.com/tools/flow.cpp
/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my libr
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <string.h>

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            bot <?= cap[u][v] - fnet[u][v] + fnet[v][u];

        // update the flow network
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}



int main(int argc,char **argv)
{
	int CASES;
	cin >> CASES;
	for(int cn=1;cn<=CASES;++cn)
	{
		int N,K;
		cin >> N >> K;
		memset(cap,0,sizeof(cap));
		vector<vector<int> > vv(N,vector<int>(K,0));
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<K;++j)
			{
				cin >> vv[i][j];
			}
		}
		for(int i=0;i<N;++i)
		{
			cap[2*N][i] = 1;
			cap[N+i][2*N+1] = 1;
			for(int j=0;j<N;++j)
			{
				if(j==i)continue;
				bool yay = true;
				for(int k=0;k<K;++k)
				{
					if(vv[i][k] >= vv[j][k]){yay = false;break;}
				}
				if(yay)
				{cap[i][N+j] = 1;}
			}
		}
		printf("Case #%d: %d\n",cn,N-fordFulkerson(2*N+2,2*N,2*N+1));
	}
	return 0;
};
