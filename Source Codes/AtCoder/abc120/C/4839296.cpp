#include <iostream>
using namespace std;
int main(void){
    int count[2] = {0};
    string S;
    cin >> S;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == '0')
            count[0]++;
        if(S[i] == '1')
            count[1]++;
    }
    cout << 2 * min(count[0], count[1]) << endl;
}