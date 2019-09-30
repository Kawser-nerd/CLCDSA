#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int alt[ 110 ][ 110 ];
int T , H , W;
int ans[ 110 ][ 110 ];
int mov[ 4 ][ 2 ] = { {-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0} };
int cnt = 0;

bool inside( int x , int y )
{
    if( x >= 0 && x < H && y >= 0 && y < W )return 1;
    return 0;
}

int dfs( int x , int y ) 
{
    if( ans[ x ][ y ] != -1 )return ans[ x ][ y ];
    int bd = -1 , bv = alt[ x ][ y ];
    for( int d = 0 ; d < 4 ; d++ )
    {
        int px = x + mov[ d ][ 0 ];
        int py = y + mov[ d ][ 1 ];
        if( !inside( px , py ) || alt[ px ][ py ] >= alt[ x ][ y ] )continue;
        if( alt[ px ][ py ] < bv )
        {
            bd = d;
            bv = alt[ px ][ py ];
        }
    }  
    if( bd == -1 )
    {
        ans[ x ][ y ] = cnt ++;
        return ans[ x ][ y ];
    }
    int ret = dfs( x + mov[ bd ][ 0 ] , y + mov[ bd ][ 1 ] );
    ans[ x ][ y ] = ret;
    return ret;
}

int main()
{
    freopen( "F.out" , "w" , stdout );
    freopen( "B-large.in" , "r" , stdin );
    //freopen( "F.in" , "r" , stdin );
    
    scanf( "%d" ,&T );
    
    for( int t = 1 ; t <= T ; t++ )
    {
        scanf( "%d%d" ,&H ,&W );
        for( int c = 0 ; c < H ; c++ )
            for( int c1 = 0 ; c1 < W ; c1++ )   
                scanf( "%d" ,&alt[ c ][ c1 ] );
        
        memset( ans , -1 , sizeof ans );
        
        cnt = 0;
        
        for( int c = 0 ; c < H ; c++ )
            for( int c1 = 0 ; c1 < W ; c1++ )
                if( ans[ c ][ c1 ] == -1 )
                    dfs( c , c1 );
        
        printf( "Case #%d:\n" ,t );
        for( int c = 0 ; c < H ; c++ )
        {
            for( int c1 = 0 ; c1 < W ; c1++ )
            {
                if( c1 > 0 )printf( " " );
                printf( "%c" ,char( 'a' + ans[ c ][ c1 ] ) );
            }
            printf( "\n" );
        }
    }
    
    return 0;
}
