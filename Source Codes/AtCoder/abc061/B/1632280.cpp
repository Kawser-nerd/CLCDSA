#include <iostream>
#include <numeric>
#define N 51

using namespace std;

int path[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= n; j+= 1)
            path[i][j] = 0;
    
    int s, g;
    while(m--) {
        cin >> s >> g;
        path[s][g]++;
        path[g][s]++;
    }

    for (int i = 1; i <= n; i += 1) {
        cout << accumulate(&path[i][0], &path[i][n+1], 0) << endl;
    }

    return 0;
}