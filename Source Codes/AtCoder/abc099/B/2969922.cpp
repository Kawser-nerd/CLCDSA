#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int b_minus_a = b - a;
    int original_height = 0;
    for (int i = 0; i <= b_minus_a - 2; i++){
        original_height += i + 1;
    }
    int ans = original_height - a;

    cout << ans << endl;
    return 0;
}