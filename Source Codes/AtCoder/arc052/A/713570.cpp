#include <iostream>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int n = 0;
    
    long l = S.length();
    for (int i=0; i<l; i++) {
        if ('0' <= (S[i]) && (S[i] <= '9')) {
            if (n > 0) {
                n = n * 10;
            }
            n += S[i] - '0';
        }
    }
    cout << n << endl;
    return 0;
}