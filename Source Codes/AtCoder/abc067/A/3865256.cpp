#include <iostream>

using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;

    if(0 == A % 3) cout << "Possible" << endl;
    else if(0 == B % 3) cout << "Possible" << endl;
    else if(0 == (A + B) % 3) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}