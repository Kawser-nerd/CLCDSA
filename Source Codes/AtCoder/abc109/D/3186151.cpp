#include <iostream>
#include <vector>
using namespace std;

int main() {

    int H, W;
    
    cin >> H >> W;

    int a[502][502];

    for(int i = 1; i <= H ; ++i ) for(int j = 1; j <= W ; ++j ) cin >> a[i][j];

    int N = 0;

    vector<int> y[2], x[2];

    for(int i = 1; i <= H ; ++i ) for(int j = 1; j < W ; ++j ) {
        if( a[i][j] % 2 == 0 ) continue;
        y[0].push_back( i ); y[1].push_back( i );
        x[0].push_back( j ); x[1].push_back(j+1);
        ++N;
        --a[i][j];
        ++a[i][j+1];
    }

    for(int i = 1; i < H ; ++i ) {
        if( a[i][W] % 2 == 0 ) continue;
        y[0].push_back( i ); y[1].push_back(i+1);
        x[0].push_back( W ); x[1].push_back( W );
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