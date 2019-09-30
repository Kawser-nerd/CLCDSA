#include <iostream>
using namespace std;

int main(void)
{
    int a,b;
    cin >> a >> b;
        
    (b % a == 0) ? cout << a+b : cout << b-a;
    return 0;
}