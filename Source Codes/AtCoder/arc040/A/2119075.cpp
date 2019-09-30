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
    int n;
    cin >> n;

    int r = 0;
    int b = 0;
    for(int i = 0; i < n * n; i++){
        char c;
        cin >> c;
        if(c == 'R'){
            r++;
        }
        if(c == 'B'){
            b++;
        }
    }

    if(r > b){
        cout << "TAKAHASHI" << endl;
        return 0;
    }
    if(r < b){
        cout << "AOKI" << endl;
        return 0;
    }
    cout << "DRAW" << endl;
    return 0;
}