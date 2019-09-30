#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X, tmp_m;
    cin >> N >> M >> X;
    vector<int> m = {};
    for(int i=0; i<M; ++i){
        cin >> tmp_m;
        m.push_back(tmp_m);
    }

    sort(m.begin(), m.end());


    int left = 0;
    int right = 0;
    for(int j=0; j<M; ++j){
        if(m[j] < X){
            ++left;
        }else{
            ++right;
        }
    }

    cout << min(left, right) << endl;

    return 0;
}