#include <iostream>
#include <vector>
using namespace std;

int main() {

    int H, W;
    
    cin >> H >> W;

    int a[502][502];

    for(int i = 1; i <= H ; ++i ) for(int j = 1; j <= W ; ++j ) cin >> a[i][j];

    int N = 0;

    int y[2][250000], x[2][250000];

    for(int i = 1; i <= H ; ++i ) for(int j = 1; j < W ; ++j ) {
        if( a[i][j] % 2 == 0 ) continue;
        y[0][N] = i, y[1][N] = i;
        x[0][N] = j, x[1][N] = j+1;
        ++N;
        --a[i][j];
        ++a[i][j+1];
    }

    for(int i = 1; i < H ; ++i ) {
        if( a[i][W] % 2 == 0 ) continue;
        y[0][N] = i, y[1][N] = i+1;
        x[0][N] = W, x[1][N] = W;
        ++N;
        --a[i][W];
        ++a[i+1][W];
    }
    
    cout << N << endl;

    for(int i = 0; i < N ; ++i ) {
        cout << y[0][i] << ' ';
        cout << x[0][i] << ' ';
        cout << y[1][i] << ' ';
        cout << x[1][i] << endl;
    }

    return 0;
}