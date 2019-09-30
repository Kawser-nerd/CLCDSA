#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> v;
    for(int i = 1; i <= N; ++i){
        int a; cin >> a;
        for(int j = 0; j < a; ++j) v.push_back(i);
    }
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(i % 2 == 0) cout << v[i*W+j];
            else cout << v[i*W+W-j-1];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}