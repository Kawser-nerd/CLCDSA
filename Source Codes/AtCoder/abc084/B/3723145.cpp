#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int A, B;
    string S;
    cin >> A >> B >> S;

    bool iszip = true;

    if(S[A] != '-')
        iszip = false;

    for(int i = 0; i < A; ++i)
        if(!isdigit(S[i]))
            iszip = false;

    for(int i = A + 1; i < A + B + 1; ++i)
        if(!isdigit(S[i]))
            iszip = false;

    cout << (iszip ? "Yes" : "No") << endl;

    return 0;
}