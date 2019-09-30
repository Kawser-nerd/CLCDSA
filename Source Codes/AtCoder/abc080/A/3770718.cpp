#include <iostream>

using namespace std;

int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(N * A, B) << endl;
    return 0;
}