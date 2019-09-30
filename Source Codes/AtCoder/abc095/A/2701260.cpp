#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int counter = 0;
    for(int i = 0; i < 3; ++i){
        if(S[i] == 'o'){
            counter += 100;
        }
    }

    cout << 700 + counter << "\n";

    return 0;
}