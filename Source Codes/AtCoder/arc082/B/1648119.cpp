#include <iostream>
using namespace std;

int main(){
    int N, ans = 0; cin >> N;
    int p[N];
    for(int i = 0; i < N; ++i) cin >> p[i];
    for(int i = 0; i < N; ++i)
    if(i+1 == p[i]){
        ans++;
        i++;
    }
    cout << ans << endl;
    return 0;
}