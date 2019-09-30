#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << ((a * b) & 1 ? "Odd" : "Even") << endl;
    return 0;
}