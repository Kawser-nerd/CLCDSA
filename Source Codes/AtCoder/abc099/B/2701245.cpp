#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int diff = b - a;

    int tall = 0;
    for(int i = 1; i <= diff; i++){
        tall += i;
    }

    int ans = tall - b;

    cout << ans << "\n";

    return 0;
}