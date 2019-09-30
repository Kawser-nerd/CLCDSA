#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); ++i){
        if(i%2 == 0){
            cout << s[i];
        }
    }
    cout << endl;

}