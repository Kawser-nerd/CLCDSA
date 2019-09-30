#include <iostream>
#include <vector>
#include <string>
#include <vector>
using namespace std;

int main(){
    char t;
    char a = 'a';
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    for(int i = 0; i < s.size(); i++){
        t = s[i];
        if(a == t) a++;
    }
    if(a > 'z'){
        cout << "None" << endl;
    }else{
        cout << a << endl;
    }
}