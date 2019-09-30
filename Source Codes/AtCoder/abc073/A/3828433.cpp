#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    if((9 == N / 10) || (9 == N % 10))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}