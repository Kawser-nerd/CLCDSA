#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int first, last;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == 'A'){
            first = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; --i){
        if (s[i] == 'Z'){
            last = i;
            break;
        }
    }
    cout << last - first + 1 << endl; 
}