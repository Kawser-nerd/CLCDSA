#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A, B) + min(C, D) << endl;
    return 0;
}