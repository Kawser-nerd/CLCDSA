#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    string S;
    char a['z'+1] = {0};
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        a[S[i]]++;
    }
    for(int i = 'a'; i <= 'z'; i++){
        if(a[i] == 0){
            char c = i;
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}