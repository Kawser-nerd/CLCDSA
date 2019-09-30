#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = 0;
    for(int i = 0;i < 3; ++i){
        if(s[i] == 'o'){
            n++;
        }
    }
    cout << 700 + n * 100 << endl;
}