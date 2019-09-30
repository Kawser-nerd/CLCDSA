#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string N;
    cin >> N;
    cout << (N[0] == N[2] ? "Yes" : "No") << endl;
    return 0;
}