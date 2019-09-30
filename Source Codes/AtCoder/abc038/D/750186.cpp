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
};
Hako hako[100000];

struct Segtree{
    int n;
    int* array;

    Segtree( int size )
    {
        n = 1;
        while( n < size )
        {
            n <<= 1;
        }
        array = new int[ 2 * n ];
        memset( array, 0, 2 * n * 4 );
    }

    int getMax( int l, int r, int index, int node_l = 0, int node_r = -1 )
    {
        if( node_r == -1 ) node_r = n;

        /* cout << l << "," << r << " : " << node_l << "," << node_r << endl; */
        if( l <= node_l && node_r <= r )
        {
            /* cout << "hoge" << endl; */
            /* cout << index << endl; */
            return array[ index ];
        }

        int mid = ( node_l + node_r ) >> 1;
        /* cout << mid << endl; */
        /* cout << l << "," << r << " : " << node_l << "," << node_r << " : " << mid << endl; */
        
        int res = 0;
        if( l < mid ) res = max( res, getMax( l, r, 2*index, node_l, mid ) );
        if( mid < r ) res = max( res, getMax( l, r, 2*index + 1, mid, node_r ) );
        return res;

        /* if( node_r < l ) */
        /* { */
        /*     return -1; */
        /* } */

        /* if( r < node_l ) */
        /* { */
        /*     return -1; */
        /* } */
        /* else */
        /* { */
        /*     /1* cout << "hoge" << endl; *1/ */
        /*     int max_l = getMax( l, r, 2 * index, node_l, mid ); */
        /*     /1* cout << max_l << endl; *1/ */
        /*     int max_r = getMax( l, r, 2 * index + 1, mid, node_r ); */
        /*     /1* cout << max_r << endl; *1/ */
        /*     return max( max_l, max_r ); */
        /* } */

        return 0;
    }

    void updateMax( int l, int r, int value, int index )
    {
        int next_index = n + index;
        while( next_index != 0 )
        {
            array[ next_index ] = max( array[ next_index ], value );
            next_index = next_index / 2;
        }
    }

    void dump()
    {
        for (int i = 0; i < 2*n; ++i)
        {
            cout << "i : " << i << " : " << array[i] << endl;
        }
    }
};

int main()
{
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
    sort( &hako[0], &hako[N], [](auto l, auto r) {
            if( l.w == r.w ) return l.h > r.h;
            else return l.w < r.w;
            } );
    /* for (auto&& v : hako) { */
    /*     cout << v.w << "," << v.h << endl; */
    /* } */

    Segtree seg( 100000 );
    for (int i = 0; i < N; ++i) {
        int max = seg.getMax( 0, hako[i].h, 1 ) + 1;
        seg.updateMax( 0, hako[i].h, max, hako[i].h );

        /* cout << hako[i].w << "," << hako[i].h << " : " << hako[i].max << endl; */
    }
    /* seg.dump(); */

    cout << seg.array[1] << endl;
}