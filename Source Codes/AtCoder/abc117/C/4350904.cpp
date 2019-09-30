#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N,M;
    cin >> N >> M;
    int x[M];
    for (int i = 0;i<M;i++){
        cin >> x[i];
    }
    sort(x,x+M);
    int y[M-1];
    for (int i = 0;i<M-1;i++){
        y[i] = x[i + 1]- x[i];
    }
    sort(y,y+M-1);
    int p = 0;
    for(int i = 0;i<(M-N);i++){
        p = p + y[i];
    }
    cout << p << endl;
}