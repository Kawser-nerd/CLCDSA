#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

string p = "welcome1to1code1jam";
int N , M;
char str[ 1000 ];
int dp[ 1000 ][ 22 ];
int np;

int calc( int i , int ind )
{
    if( ind == np )return 1;
    if( i == M )return 0;
    int &ret = dp[ i ][ ind ];
    if( ret != -1 )return ret;
    ret = 0;
    ret += calc( i + 1 , ind );
    ret %= 10000;
    if( p[ ind ] == str[ i ] )
    {
        ret += calc( i + 1 , ind + 1 );
        ret %= 10000;
    }
    return ret;
}

string mody( int x )
{
    char y[ 55 ];
    sprintf( y , "%d" ,x );
    string ret = y;
    while( ret.size() < 4 )ret = "0" + ret;
    return ret;
}

int main()
{
    freopen( "F.out" , "w" , stdout );
    freopen( "C-large.in" , "r" , stdin );
    //freopen( "inp.in" , "r" , stdin );
    
    np = p.size();
    scanf( "%d\n" ,&N );
    
    for( int c = 0 ; c < N ; c++ )
    {
        M = 0;
        char ch;
        scanf( "%c" ,&ch );
        string gg;
        while( ch != '\n' )
        {
            gg = ch;
            if( gg == " " )
                str[ M ] = '1';
            else
                str[ M ] = ch;
            M ++;
            scanf( "%c" ,&ch );
        }
        str[ M ] = '\0';
        
        memset( dp , -1 , sizeof dp );
        int ret = calc( 0 , 0 );
        printf( "Case #%d: %s\n" , c + 1 , mody( ret ).c_str() );
    }
    
    return 0;
}
