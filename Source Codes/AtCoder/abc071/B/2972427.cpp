#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){

    int alpha[30];
    string s;

    cin >> s;

    for(int i = 0 ; i < 30; ++i){
        alpha[i] = false;
    }

    for(int i = 0; s[i] != '\0'; ++i){
        alpha[ s[i]-'a' ] = true;
    }

    for(int i = 0; i < 26; ++i){
        if(alpha[i] == false){
            cout << (char) (i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}