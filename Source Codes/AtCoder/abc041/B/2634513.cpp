#include <iostream>
#include <string>

using namespace std;
long long A, B, C;
long long D = 1000000007;

int main() {
    cin >> A >> B >> C;
    cout << A * B % D * C % D << endl;
}