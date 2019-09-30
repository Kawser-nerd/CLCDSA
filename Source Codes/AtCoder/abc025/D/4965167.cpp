#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MOD ( 1000000000 + 7 )
#define MAX 5

struct Position
{
private:
    int row;
    int col;

public:
    Position() : row( 0 ), col( 0 ) {}
    Position( int row, int col ) : row( row ), col( col ) {}
    Position( int num )
    {
        this->row = num / MAX;
        this->col = num % MAX;
    }

    int Row() { return this->row; }
    int Col() { return this->col; }
    int ToBin() { return 1 << ( this->ToNum() ); }
    int ToNum() { return this->row * MAX + this->col; }

    Position Right() { return Position( this->row, this->col + 1 ); }
    Position Left() { return Position( this->row, this->col - 1 ); }
    Position Up() { return Position( this->row + 1, this->col ); }
    Position Down() { return Position( this->row - 1, this->col ); }

    bool IsRightEdge() { return this->col == MAX - 1; }
    bool IsLeftEdge() { return this->col == 0; }
    bool IsUpEdge() { return this->row == MAX - 1; }
    bool IsDownEdge() { return this->row == 0; }

    static vector<Position> All()
    {
        vector<Position> v;
        for ( int i = 0; i < MAX * MAX; i++ ) v.push_back( Position( i ) );
        return v;
    }
};

struct State
{
private:
    int v;

public:
    State() : v( 0 ) {}
    State( int v ) : v( v ) {}

    int V() { return this->v; }
    State PutOn( Position p ) { return State( this->v | p.ToBin() ); }
    bool Has( Position p ) { return ( this->v & p.ToBin() ) > 0; }
    bool CanPutOn( Position p )
    {
        if ( !p.IsRightEdge() && !p.IsLeftEdge() )
        {
            bool l = this->Has( p.Left() );
            bool r = this->Has( p.Right() );

            if ( ( l && !r ) || ( !l && r ) ) return false;
        }

        if ( !p.IsUpEdge() && !p.IsDownEdge() )
        {
            bool u = this->Has( p.Up() );
            bool d = this->Has( p.Down() );

            if ( ( u && !d ) || ( !u && d ) ) return false;
        }

        return true;
    }
};

bool exist[MAX * MAX];
bool blank[MAX * MAX];
Position pos[MAX * MAX];

int dp[1 << ( MAX * MAX )];

long long dfs( State sts, int num )
{
    if ( dp[sts.V()] >= 0 ) { return dp[sts.V()]; }

    long long res = 0;
    if ( exist[num] )
    {
        if ( sts.CanPutOn( pos[num] ) )
        {
            res += dfs( sts.PutOn( pos[num] ), num + 1 );
            res %= MOD;
        }
    }
    else
    {
        for ( auto p : Position::All() )
        {
            if ( sts.Has( p ) ) continue;
            if ( blank[p.ToNum()] == false ) continue;
            if ( !sts.CanPutOn( p ) ) continue;

            res += dfs( sts.PutOn( p ), num + 1 );
            res %= MOD;
        }
    }
    return dp[sts.V()] = res;
}

int main()
{
    for ( auto p : Position::All() )
    {
        int x;
        cin >> x;

        if ( x )
        {
            exist[x - 1] = 1;
            pos[x - 1] = p;
        }
        else
        {
            blank[p.ToNum()] = true;
        }
    }

    memset( dp, -1, sizeof( dp ) );
    dp[( 1 << ( MAX * MAX ) ) - 1] = 1;
    long long ans = dfs( State(), 0 );

    cout << ans << endl;

    return 0;
}