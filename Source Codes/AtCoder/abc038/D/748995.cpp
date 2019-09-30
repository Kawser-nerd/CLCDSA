#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<utility>   
#include<math.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;

struct Hako{
    int h;
    int w;
    int max;
};

Hako hako[100000];

struct Node{
    int low;
    int high;
    int max;
};

const int cTreeLength = 1024*128;
/* const int cTreeLength = 16; */
Node segtree[2*cTreeLength];

bool compareW(const Hako &lhs, const Hako &rhs)
{
    if( lhs.w == rhs.w )
        return lhs.h > rhs.h;
    else
        return lhs.w < rhs.w;
}

int getMax( int low, int high, int index )
{
    /* cout << "low:" << low << "high:" << high << " index " << index << endl; */
    Node& node = segtree[ index ];
    if( low <= node.low && node.high <= high )
    {
        return segtree[ index ].max;
    }

    if( node.high < low)
    {
        return -1;
    }

    if( high < node.low )
    {
        return -1;
    }
    else
    {
        int max_l = getMax( low, high, 2 * index );
        int max_r = getMax( low, high, 2 * index + 1 );
        return max( max_l, max_r );
    }

    return 0;
}

void updateMax( int value, int h )
{
    /* segtree[ index ].max = value; */

    int next_index = cTreeLength + h;
    while( next_index != 0 )
    {
        segtree[ next_index ].max = max( segtree[ next_index ].max, value );
        next_index = next_index / 2;
    }
}

void dump()
{
    for (int i = 0; i < 2*cTreeLength; ++i)
    {
        cout << "i : " << i << " : " << segtree[i].low << "," << segtree[i].high << " :: "  << segtree[i].max << endl;
    }
}

int main()
{
    memset( segtree, 0, sizeof( segtree ) );

    // get a integer
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int w, h;
        scanf( "%d %d", &w, &h );
        hako[i].w = w;
        hako[i].h = h;
        /* cout << hako[i].w << "," << hako[i].h << endl; */
    }

    //initialize segtree
    segtree[1].low = 1;
    segtree[1].high = cTreeLength;
    for (int i = 1; i <= cTreeLength; ++i)
    {
        int parent = i;

        int mid = ( segtree[parent].low + segtree[parent].high ) / 2;
        segtree[2*i].low    = segtree[parent].low;
        segtree[2*i].high   = mid;
        segtree[2*i+1].low  = mid + 1;
        segtree[2*i+1].high = segtree[parent].high;
    }

    sort( &hako[0], &hako[N], compareW );
    int counterW = 1;
    /* int prev_w = 0; */
    for (int i = 0; i < N; ++i) {
        /* if( prev_w == hako[i].w ) */
        /* { */
        /*     continue; */
        /* } */
        hako[i].max = getMax( 1, hako[i].h, 1 ) + 1;
        updateMax( hako[i].max, hako[i].h );

        /* cout << hako[i].w << "," << hako[i].h << " : " << hako[i].max << endl; */
        /* dump(); */

        /* prev_w = hako[i].w; */
    }

    cout << segtree[1].max << endl;
}