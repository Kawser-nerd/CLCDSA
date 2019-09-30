#include <iostream>

using namespace std;

int main(void)
{
    int N, A;
    cin >> N >> A;
    cout << ((A - N % 500) >= 0 ? "Yes" : "No") << endl;
    return 0;
}