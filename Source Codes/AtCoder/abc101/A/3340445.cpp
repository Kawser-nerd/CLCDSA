#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = 0;
    for(int i=0; i< 4; ++i){
        if(s[i] == '+'){
            n ++;
        }
        if(s[i] == '-'){
            n --;
        }
    }
    cout << n << endl;
}