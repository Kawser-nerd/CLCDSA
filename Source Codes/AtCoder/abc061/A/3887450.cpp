#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    if(A <= C && C <= B) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}