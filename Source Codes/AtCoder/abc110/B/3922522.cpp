#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int X,Y,N,M;
    cin >> N >> M >> X >> Y;
    vector<int> x(N),y(M);
    for (int i = 0; i < N; i++){
        cin >> x[i];
    }
    for (int i = 0; i < M; i++){
        cin >> y[i];
    }
    bool ok = false;
    int maxX = *max_element(all(x));
    int minY = *min_element(all(y));
    for (int i = X+1; i <= Y; i++){
        if (maxX < i && i <= minY){
            ok = true;
        }
    }
    if (ok){
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }



    return 0;
}