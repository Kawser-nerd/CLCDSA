#include <iostream>

using namespace std;

int main(void)
{
    int N; cin >> N;
    cout << "AB" << char(('C' + (N / 1000))) << endl;
    return 0;
}