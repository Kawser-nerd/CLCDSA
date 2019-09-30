#include <iostream>
using namespace std;

int main() {
    int N;
    int a[10000];

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++){
        int n = a[i];
        while (n % 2 == 0){
            ans += 1;
            n /= 2;
        }
    }

    cout << ans << endl;
    return 0;
}