#include <iostream>

using namespace std;

int main(void)
{
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    cout << min(K, N) * X + max(N - K, 0) * Y << endl;
    return 0;
}