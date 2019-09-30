#include <iostream>
using namespace std;

int main(){
    int m, n, N;
    cin >> m >> n >> N;
    
    int ans = N, temp = 0;

    while(N >= m){
        temp = N % m;
        N = N / m * n + temp;
        ans += N - temp;
    }

    cout << ans << endl;

    return 0;
}