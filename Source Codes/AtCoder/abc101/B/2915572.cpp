#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int S = 0;
    int n = N;

    while (n > 0){
        S += n % 10;
        n /= 10;
    }

    if (N % S == 0){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}