#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string A, B, C;
    cin >> A >> B >> C;

    if((*A.rbegin() == *B.begin()) && (*B.rbegin() == *C.begin()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}