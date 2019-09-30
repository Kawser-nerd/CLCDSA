#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){

    int N, M;
    int a[55], b[55];
    int ans;

    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        cin >> a[i] >> b[i];
    }

    for(int i = 1; i <= N; ++i){
        ans = 0;
        for(int j = 0; j < M; ++j){
            if(i == a[j] || i == b[j]){
                ++ans;
            }
        }
        cout << ans << endl;
    }
}