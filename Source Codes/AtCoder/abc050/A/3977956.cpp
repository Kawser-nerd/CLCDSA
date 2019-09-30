#include <iostream>

using namespace std;

int main(void)
{
    int A, B;
    char op;
    cin >> A >> op >> B;

    if(op == '+') cout << A + B << endl;
    else cout << A - B << endl;
    return 0;
}