#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            if(b[i][j] == 0){
                continue;
            }
            a[i+1][j] = b[i][j];
            b[i+1][j-1] -= b[i][j];
            b[i+1][j+1] -= b[i][j];
            b[i+2][j] -= b[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}