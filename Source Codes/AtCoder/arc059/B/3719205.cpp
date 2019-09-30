#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    int len, l, r;
    cin >> s;
    len = s.length();
    l = -1;
    r = -1;
    if(len == 2){
        if(s[0] == s[1]){
            l = 1;
            r = 2;
        }
    }
    else {
        for(int i=0; i<len-2; ++i){
            if(s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]){
                l = i+1;
                r = i+3;
                break;
            }
        }
    }
    cout << l << " " << r << endl;
}