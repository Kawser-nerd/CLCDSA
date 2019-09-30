#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, max_profit, profit, c, l;
    vector<vector<vector<int>>> f;
    vector<vector<int>> p;
    cin >> n;
    f.resize(n);
    p.resize(n);
    max_profit = -2000000000;
    for(int i=0; i<n; ++i){
        f[i].resize(5);
        for(int j=0; j<5; ++j){
            f[i][j].resize(2);
            for(int k=0; k<2; ++k){
                cin >> f[i][j][k];
            }
        }
    }
    for(int i=0; i<n; ++i){
        p[i].resize(11);
        for(int j=0; j<=10; ++j){
            cin >> p[i][j];
        }
    }
    bitset<10> b;
    for(unsigned int m=1; m<1024; ++m){
        b = static_cast<bitset<10>>(m);
        profit = 0;
        for(int i=0; i<n; ++i){
            c = 0;
            for (int j=0; j<5; ++j){
                for(int k=0; k<2; ++k){
                    l = k + 2 * j;
                    if(f[i][j][k] == 1 && b[l] == 1){
                        c++;
                    }
                }
            }
            profit += p[i][c];
        }
        max_profit = max(profit, max_profit);
    }
    cout << max_profit << endl;
}