#include <iostream>

using namespace std;

int main(void)
{
    uint64_t N; cin >> N;
    cout << (N % 2 ? N * 2 : N) << endl;
    return 0;
}