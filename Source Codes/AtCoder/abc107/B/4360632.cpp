#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int H,W;
    cin >> H >> W;
    char a[H][W];
    for (int i = 0;i<H;i++){
        for (int j = 0;j<W;j++)
        cin >> a[i][j];
    }
    vector<int> h,w;
    for (int i = 0;i < H;i++){
        for(int j = 0;j<W;j++){
            if(a[i][j] == '#'){
                h.push_back(i);
                break;
            }
        }
    }
    for (int i = 0;i < W;i++){
        for(int j = 0;j<H;j++){
            if(a[j][i] == '#'){
                w.push_back(i);
                break;
            }
        }
    }
    for (int i = 0;i<h.size();i++){
        for(int j = 0;j<w.size();j++){
            cout << a[h[i]][w[j]] ;
        }
        cout << endl;
    }
}