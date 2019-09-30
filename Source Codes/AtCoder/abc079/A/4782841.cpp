#include <iostream>

using namespace std;

int main() {

    string S;
    cin >> S;
    if(S[0]==S[1] && S[1] ==S[2])cout << "Yes" <<endl;
    else if(S[1]==S[2] && S[2] ==S[3])cout << "Yes" <<endl;
    else cout << "No" << endl;
    return 0;
}