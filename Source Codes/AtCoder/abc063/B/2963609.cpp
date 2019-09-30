#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){

    string s;
    set<char> backet;

    cin >> s;

    for(int i = 0; i < s.size(); ++i){
        if(backet.count(s[i]) == 1){
            cout << "no" << endl;
            return 0;
        }
        backet.insert(s[i]);
    }

    cout << "yes" << endl;
    return 0;
}