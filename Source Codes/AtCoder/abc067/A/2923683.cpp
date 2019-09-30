#include <iostream>

using namespace std;

int main()
{
    int a, b; cin >> a >> b; cout << (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0 ? "Possible" : "Impossible") << endl;
     
    return 0;
}