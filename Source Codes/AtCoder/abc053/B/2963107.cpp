#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){
    string s;
    int Zindex=0, Aindex=0;

    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'A'){
            Aindex = i;
            break;
        }
    }
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'Z'){
            Zindex = max(i, Zindex); 
        }
    }

    cout << Zindex - Aindex +1 << endl;
}