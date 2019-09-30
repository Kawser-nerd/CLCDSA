#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S, T;

    cin >> S >> T;

    S += S;

    if(string::npos == S.find(T)) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}