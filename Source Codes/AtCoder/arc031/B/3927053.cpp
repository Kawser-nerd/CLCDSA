#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
#include <array>

using namespace std;

void search(vector<string>& a, vector<vector<int>>& f, vector<vector<int>>& c, int h, int w){
    int dw[4] = {1, 0, -1, 0};
    int dh[4] = {0, -1, 0, 1};
    a[h][w] = 'x';
    for (int i=0; i<4; ++i){
        if(0 <= h + dh[i] && h + dh[i] < 10 && 0 <= w + dw[i] && w + dw[i] < 10){
            if(a[h+dh[i]][w+dw[i]] == 'o'){
                search(a, f, c, h+dh[i], w+dw[i]);
            }
            else if(c[h+dh[i]][w+dw[i]] == 0 && a[h+dh[i]][w+dw[i]] == 'x'){
                c[h+dh[i]][w+dw[i]] = 1;
                f[h+dh[i]][w+dw[i]]++;
            }
        }
    }
}

int main()
{
    vector<string> a(10);
    vector<vector<int>> f(10);
    vector<vector<int>> check(10);
    int land = 0;
    for (int i=0; i<10; ++i){
        cin >> a[i];
        f[i].resize(10);
        check[i].resize(10);
        for (int j=0; j<10; ++j){
            f[i][j] = 0;
            if(a[i][j] == 'x'){
                check[i][j] = 0;
            }
            else {
                check[i][j] = -1;
            }
        }
    }
    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j){
            if(a[i][j] == 'x'){
                continue;
            }
            for (int p=0; p<10; ++p){
                for (int q=0; q<10; ++q){
                    check[p][q] = (check[p][q] >= 0) ? 0 : -1;
                }
            }
            search(a, f, check, i, j);
            land++;
        }
    }
    string ans = "NO";
    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j){
            if(land == f[i][j]){
                ans = "YES";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}