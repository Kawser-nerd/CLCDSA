#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    string ans = "ABD";
    if (N<1000){
        ans = "ABC";
    }

    cout << ans << endl;
    return 0;
}