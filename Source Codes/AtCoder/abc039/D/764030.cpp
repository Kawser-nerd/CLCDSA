#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

int W, H;
const int cSize = 102;
bool input[cSize][cSize];
char output[cSize][cSize];


bool isOver( int x, int y )
{
    return ( x < 0 ) || ( y < 0 ) || ( x >= W ) ||  ( y >= H );
}

bool isAllBlack( int x, int y )
{
    int vx[] = { 1, -1, 0 };
    int vy[] = { 1, -1, 0 };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int nx = x + vx[i];
            int ny = y + vy[j];
            if( isOver( nx, ny ) )
            {
                continue;
            }

            if( input[nx][ny] == false )
            {
                return false;
            }
        }
    }
    return true;
}

bool isPlacable( int x, int y )
{
    int vx[] = { 1, -1, 0 };
    int vy[] = { 1, -1, 0 };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int nx = x + vx[i];
            int ny = y + vy[j];
            if( isOver( nx, ny ) )
            {
                continue;
            }

            if( isAllBlack( nx, ny ) )
            {
                output[nx][ny] = '#';
                return true;
            }
        }
    }
    return false;
}


int main()
{
    memset( input, 0, cSize * cSize * sizeof( input[0][0] ) );
    memset( output, '\n', cSize * cSize * sizeof( output[0][0] ) );
    // get a integer
    cin >> H >> W;

    /* cout << W << "," << H << endl; */

    for (int y = 0; y < H; ++y) {
        char str[100];
        scanf("%s", str);
        /* cout << str << endl; */
        for (int x = 0; x < W; ++x) {
            output[x][y] = '.';
            if( str[x] == '#' )
            {
                input[x][y] = true;
            }
            else
            {
                input[x][y] = false;
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if( input[x][y] )
            {
                bool result = isPlacable( x, y );
                /* cout << x << "," << y << ": " << result << endl; */
                if( !result )
                {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "possible" << endl;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cout << output[x][y];
        }
        cout << endl;
    }
}