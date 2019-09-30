#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b; cin >> a >> b; cout << (a + b < 10 ? to_string(a + b): "error") << endl;
    return 0;
}